#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

bool readJsonlFile(const string& name, json& allNotifs) {
    ifstream f(name.c_str());
    if (!f.is_open()) {
        cerr << "Error: could not open file " << name << "\n";
        allNotifs = json::array(); // Explicitly set to empty array on failure
        return false;
    }

    allNotifs = json::array();
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        try {
            json notification = json::parse(line);
            if (!notification.contains("app") || !notification.contains("summary") ||
                !notification.contains("body") || !notification.contains("time")) {
                cerr << "Skipping invalid notification: missing required fields\n";
                continue;
            }
            json formatted = {
                {"app_name", notification["app"]},
                {"summary", notification["summary"]},
                {"body", notification["body"]},
                {"time", notification["time"]}
            };
            allNotifs.push_back(formatted);
        } catch (const json::parse_error& e) {
            cerr << "Error parsing JSON line: " << line << " (" << e.what() << ")\n";
        }
    }
    f.close();
    return !allNotifs.empty();
}

string getHomePath() {
    const char* home = getenv("HOME");
    if (home) {
        return string(home);
    }
    return "/home/sovetskaya_russiya"; // Fallback if HOME is not set
}

int main() {
    json allNotifs;
    string homeDir = getHomePath();
    string filePath = homeDir + "/.cache/quickshell-notif-log.json";
    if (const char* envPath = getenv("NOTIF_LOG_PATH")) {
        filePath = envPath;
    }
    if (!readJsonlFile(filePath, allNotifs)) {
        cout << "[]" << '\n' << std::flush; // Force empty array on failure
    } else {
        cout << allNotifs.dump() << '\n' << std::flush; // Output populated array
    }
    return 0;
}

// for dunst fr

// #include <array>
// #include <fstream>
// #include <iostream>
// #include <memory>
// #include <stdexcept>
// #include <string>
// // #include <filesystem>
// // #include <vector>

// #include "nlohmann/json.hpp"
// using namespace std;
// using json = nlohmann::json;

// string dunstOutput;
// json allNotifs, notifApps;

// string exec(const char* cmd){
//     array<char, 128> buffer;
//     string result;
//     unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
//     if (!pipe){
//         throw runtime_error("popen() failed!");
//     }
//     while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr){
//         result += buffer.data();
//     }
//     return result;
// }

// // Function to check if file exists, if yes read it
// string readIfExists(const string& name){
//     ifstream f(name.c_str());
//     stringstream buffer;
//     if (f){                    // check if the file was opened successfully
//         buffer << f.rdbuf();  // read the whole file into a string stream
//         f.close();            // close the file when done
//     }
//     return buffer.str();  // return the string stream as a string
// }

// void writeToFile(const string& name, const string& content) {
//     ofstream f(name.c_str(), ios::app);  // open the file in append mode
//     if (f){                     // check if the file was opened successfully             
//         f << content << "\n";  // write the content to the file
//         f.close();             // close the file when done
//     }else{
//         cerr << "Error: could not open " << name
//              << "\n";  // print an error message to the standard error
//     }
// }

// inline bool getDunstNotifs(){
//     dunstOutput = exec("dunstctl history | gojq -c -M");
//     if(dunstOutput.empty()){
//         cerr << "No notifications data returned. Is Dunst stop working?\n";
//         return false;
//     }
//     allNotifs = json::parse(dunstOutput)["data"][0];
//     return true;
// }

// void addNotif(const json& newNotification){
//     notifApps["count"] = int(notifApps["count"]) + 1;
//     bool found = false;

//     for (json& existingApp : notifApps["data"]){
//         auto it = existingApp.find("name");

//         if (it != existingApp.end() &&
//             *it == newNotification["appname"]["data"]){
//             found = true;
//             existingApp["count"] = int(existingApp["count"]) + 1;
//             existingApp["content"].push_back(
//                 json::array({newNotification["summary"]["data"],
//                              newNotification["body"]["data"]}));
//             break;
//         }
//     }
//     // Not found? A new app it is
//     if (!found){
//         json newApp = R"({"name": "", "count": 1, "content": []})"_json;
//         newApp["name"] = string(newNotification["appname"]["data"]);
//         newApp["content"].push_back(
//             json::array({newNotification["summary"]["data"],
//                          newNotification["body"]["data"]}));

//         notifApps["data"].push_back(newApp);
//     }
// }

// inline void groupNotifs(){
//     for (json notification : allNotifs){
//         addNotif(notification);
//     }
// }

// int main(){
//     // ios::sync_with_stdio(false);
//     if (!getDunstNotifs()){
//         return 1;
//     }
//     else {
//         notifApps["data"] = json::array();
//         notifApps["count"] = 0;
    
//         // getDunstNotifs();
//         groupNotifs();
//         cout << notifApps << '\n';
    
//     }
// }