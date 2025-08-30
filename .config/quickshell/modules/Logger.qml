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
    property int maxAgeMinutes: 1
    property int maxEntries: 50    

    // Function to append and prune notifications
    function appendNotification(notification) {
        if (!notification) {
            console.warn("appendNotification: Notification is undefined")
            return
        }

        console.log("Processing notification:", notification.appName, notification.summary)
        var date = new Date()
        var formattedTime = date.toLocaleString('en-GB', { hour: '2-digit', minute: '2-digit' }) // Time only (HH:MM)
        var timestamp = Math.floor(date.getTime() / 1000) // Unix timestamp in seconds
        var entry = {
            app: notification.appName || "Unknown",
            summary: notification.summary || "",
            body: notification.body || "",
            time: formattedTime,
            timestamp: timestamp
        }

        var entryStr = JSON.stringify(entry) + "\n"
        var currentContent = logFileHandle.text() || ""
        var lines = currentContent.split("\n").filter(line => line.trim() !== "")
        lines.push(entryStr)
        lines = pruneAndSortNotifications(lines) // Use the returned sorted list
        logFileHandle.setText(lines.join("\n"))

    }

    // Function to prune, sort, and limit notifications
    function pruneAndSortNotifications(lines) {
        var now = new Date()
        var cutoffTimestamp = Math.floor((now.getTime() - maxAgeMinutes * 60 * 1000) / 1000)

        // Filter
        var filtered = lines.filter(line => {
            try {
                var entry = JSON.parse(line)
                return entry.timestamp ? entry.timestamp >= cutoffTimestamp : true
            } catch (e) {
                console.warn("Failed to parse line:", line, e)
                return false
            }
        })

        // Sort newest first
        filtered.sort((a, b) => {
            try {
                var aTime = JSON.parse(a).timestamp || 0
                var bTime = JSON.parse(b).timestamp || 0
                return bTime - aTime
            } catch (e) {
                console.warn("Sorting error:", e)
                return 0
            }
        })

        // Limit entries
        if (filtered.length > maxEntries) {
            filtered = filtered.slice(0, maxEntries)
        }

        return filtered
    }

    // Consolidated Component.onCompleted
    Component.onCompleted: {
        console.log("FileView path:", logFileHandle.path)
        console.log("FileView exists:", logFileHandle.exists)
        var date = new Date()
        var formattedTime = date.toLocaleString('en-GB', { hour: '2-digit', minute: '2-digit' }) // Time only (HH:MM)
        var timestamp = Math.floor(date.getTime() / 1000) // Unix timestamp in seconds
        var currentContent = logFileHandle.text() || ""
        var lines = currentContent.split("\n").filter(line => line.trim() !== "")
        lines = pruneAndSortNotifications(lines) // Sort and prune initial content
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
                lines = pruneAndSortNotifications(lines)
                logFileHandle.setText(lines.join("\n"))
            }
        }
    }
}