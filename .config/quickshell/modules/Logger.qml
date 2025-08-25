import QtQuick
import Quickshell
import Quickshell.Services.Notifications as Notifs
import Quickshell.Io  // For FileView

QtObject {
    // Use Quickshell.env to resolve HOME directory
    property string logFile: Quickshell.env("HOME") + "/.cache/quickshell-notif-log.json"

    // FileView for reading/writing the log file
    property var logFileHandle: FileView {
        path: logFile
        preload: true
        printErrors: true
        atomicWrites: true
        watchChanges: false
        onLoadFailed: { console.warn("FileView load failed:", error) }
        onSaveFailed: console.warn("FileView save failed:", error)
    }

    // NotificationServer instance
    property var notificationServer: Notifs.NotificationServer {
        bodySupported: true
        keepOnReload: true
    }

    // Auto-delete settings
    property int maxAgeMinutes: 30  // Delete notifications older than 30 minutes (adjustable to 12)
    property int maxEntries: 50     // Maximum number of notifications to keep

    // Function to append and prune notifications
    function appendNotification(notification) {
        if (!notification) {
            console.warn("appendNotification: Notification is undefined")
            return
        }

        console.log("Processing notification:", notification.appName, notification.summary)
        var date = new Date()
        var formattedTime = date.toLocaleString('en-US', { year: 'numeric', month: '2-digit', day: '2-digit', hour: '2-digit', minute: '2-digit' })
        var entry = {
            app: notification.appName || "Unknown",
            summary: notification.summary || "",
            body: notification.body || "",
            time: formattedTime
        }

        var entryStr = JSON.stringify(entry) + "\n"
        var currentContent = logFileHandle.text() || ""
        var lines = currentContent.split("\n").filter(line => line.trim() !== "")
        lines.push(entryStr)
        pruneNotifications(lines)
        logFileHandle.setText(lines.join("\n"))
    }

    // Function to prune old or excess notifications
    function pruneNotifications(lines) {
        var now = new Date()
        var cutoff = new Date(now.getTime() - maxAgeMinutes * 60 * 1000) // Convert minutes to milliseconds
        lines = lines.filter(line => {
            try {
                var entry = JSON.parse(line)
                if (entry.time) {
                    var entryDate = new Date(entry.time)
                    return entryDate >= cutoff && lines.length <= maxEntries
                }
                return true
            } catch (e) {
                console.warn("Failed to parse line:", line, e)
                return false
            }
        })

        // If still over maxEntries after age filter, keep the newest ones
        if (lines.length > maxEntries) {
            lines.sort((a, b) => {
                var aDate = JSON.parse(a).time ? new Date(JSON.parse(a).time) : new Date(0)
                var bDate = JSON.parse(b).time ? new Date(JSON.parse(b).time) : new Date(0)
                return bDate - aDate
            })
            lines = lines.slice(0, maxEntries)
        }
    }

    // Consolidated Component.onCompleted
    Component.onCompleted: {
        console.log("FileView path:", logFileHandle.path)
        console.log("FileView exists:", logFileHandle.exists)
        var date = new Date()
        var formattedTime = date.toLocaleString('en-US', { year: 'numeric', month: '2-digit', day: '2-digit', hour: '2-digit', minute: '2-digit' })
        var startupEntry = JSON.stringify({ app: "Logger", summary: "Startup", body: "Logger initialized", time: formattedTime }) + "\n"
        var currentContent = logFileHandle.text() || ""
        var lines = currentContent.split("\n").filter(line => line.trim() !== "")
        lines.push(startupEntry)
        pruneNotifications(lines)
        if (logFileHandle.setText(lines.join("\n"))) {
            console.log("Wrote startup entry to:", logFile)
        } else {
            console.warn("Failed to append startup entry to:", logFile)
        }

        if (notificationServer) {
            console.log("NotificationServer is available")
            var tracked = notificationServer.trackedNotifications
            if (tracked && typeof tracked.count !== "undefined") {
                console.log("Tracked notifications count:", tracked.count)
                for (var i = 0; i < tracked.count; i++) {
                    var notif = tracked.get(i)
                    appendNotification(notif)
                }
            } else {
                console.warn("Tracked notifications is undefined or has no count")
            }
        } else {
            console.warn("NotificationServer is undefined")
        }
    }

    // Connections for new notifications
    property var notifConnections: Connections {
        target: notificationServer || null
        ignoreUnknownSignals: true
        function onNotification(notification) {
            console.log("New notification received")
            notification.tracked = true
            appendNotification(notification)
        }
    }

    // Timer to check and prune periodically
    property var notificationTimer: Timer {
        interval: 300000  // Check every 5 minutes
        running: true
        repeat: true
        onTriggered: {
            if (notificationServer && notificationServer.trackedNotifications) {
                console.log("Checking tracked notifications, count:", notificationServer.trackedNotifications.count || "undefined")
                var currentContent = logFileHandle.text() || ""
                var lines = currentContent.split("\n").filter(line => line.trim() !== "")
                pruneNotifications(lines)
                logFileHandle.setText(lines.join("\n"))
            }
        }
    }
}