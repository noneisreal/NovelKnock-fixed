// #include <boost/iostreams/device/file_descriptor.hpp>
// #include <boost/iostreams/stream.hpp>
// #include <cstdio>
// #include <iostream>
// #include <memory>
// #include <stdexcept>
// #include <string>

// void cavaToJson(std::string& s)
// {
//     int cnt = 0;
//     std::string newStr = "[";
//     for (int i = 0; i < s.size(); i++) 
//     {
//         if (s[i] == ';') 
//         {
//             s[i] = ',';
//             newStr += std::string(',' + std::to_string(cnt++) + "],[");
//         }
//         else 
//         {
//             newStr.push_back(s[i]);
//         }
//     }
//     newStr.pop_back();
//     newStr.pop_back();
//     s = newStr;
// }

// int main() 
// {
//     std::unique_ptr<FILE, decltype(&pclose)> pipe(
//         popen("cava -p ~/.config/eww/scripts/custom_configs/cava", "r"),
//         pclose);
//     if (!pipe) 
//     {
//         throw std::runtime_error("popen() failed!");
//     }
//     boost::iostreams::file_descriptor_source fd(
//         fileno(pipe.get()), boost::iostreams::never_close_handle);
//     boost::iostreams::stream<boost::iostreams::file_descriptor_source> is(fd);
//     std::string line;
//     while (std::getline(is, line)) 
//     {
//         cavaToJson(line);
//         std::cout << '[' << line << ']'
//                   << std::endl;  // print the output line by line
//     }
//     return 0;
// }

#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

using boost::iostreams::file_descriptor_source;
using boost::iostreams::never_close_handle;
using boost::iostreams::stream;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;
using namespace std;

void kill_existing_cava() {
    system("pkill -f 'cava -p ~/.config/eww/scripts/custom_configs/cava' 2>/dev/null");
}

void cavaToJson(string &s) {
  if (s.empty() || s == ";" || s.find_first_not_of(";") == string::npos) {
    s = "[]";
    return;
  }
  s.insert(0, "[");
  std::replace(s.begin() + 1, s.end(), ';', ',');
  if (s.back() == ',') {
    s.pop_back();
  }
  s += "]";
}

int main() {
  // kill cava  
  kill_existing_cava();
    using pipe_ptr = unique_ptr<FILE, decltype(&pclose)>;
    pipe_ptr pipe(popen("cava -p ~/.config/eww/scripts/custom_configs/cava 2>/dev/null", "r"), pclose);
    if (!pipe) {
        cerr << "Error: popen() failed" << endl;
        cout << "[]" << endl;
        return 1;
    }
    file_descriptor_source fd(fileno(pipe.get()), never_close_handle);
    stream<file_descriptor_source> is(fd);
    string line;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (getline(is, line)) {
        cavaToJson(line);
        cout << line << '\n';
        cout.flush();
        sleep_for(milliseconds(50));
    }
    return 0;
}

// #include <boost/iostreams/device/file_descriptor.hpp>
// #include <boost/iostreams/stream.hpp>
// #include <nlohmann/json.hpp>
// #include <cstdio>
// #include <iostream>
// #include <memory>
// #include <string>
// #include <algorithm>
// #include <chrono>
// #include <thread>

// using boost::iostreams::file_descriptor_source;
// using boost::iostreams::stream;
// using std::chrono::milliseconds;
// using std::this_thread::sleep_for;
// using namespace std;

// // Avoid compiler warning by defining pipe_ptr globally
// using pipe_ptr = unique_ptr<FILE, decltype(&pclose)>;

// void cavaToJson(string &s, const nlohmann::json &colors) {
//     nlohmann::json output;
//     if (s.empty() || s == ";" || s.find_first_not_of(";") == string::npos) {
//         output["bars"] = nlohmann::json::array();
//     } else {
//         s.insert(0, "[");
//         std::replace(s.begin() + 1, s.end(), ';', ',');
//         if (s.back() == ',') {
//             s.pop_back();
//         }
//         s += "]";
//         try {
//             output["bars"] = nlohmann::json::parse(s);
//         } catch (...) {
//             output["bars"] = nlohmann::json::array();
//         }
//     }
//     output["colors"] = colors;
//     s = output.dump();
// }

// nlohmann::json getColors() {
//     string cmd = "~/.config/eww/scripts/music cover";
//     pipe_ptr pipe(popen(cmd.c_str(), "r"), pclose);
//     if (!pipe) {
//         return {
//             {"primary", "#c3c0ff"},
//             {"onPrimary", "#282377"},
//             {"primaryContainer", "#3f3c8f"},
//             {"onPrimaryContainer", "#e2dfff"}
//         };
//     }
//     file_descriptor_source fd(fileno(pipe.get()), boost::iostreams::never_close_handle);
//     stream<file_descriptor_source> is(fd);
//     string line;
//     if (getline(is, line)) {
//         try {
//             auto json = nlohmann::json::parse(line);
//             nlohmann::json filtered_colors;
//             for (const auto& [key, value] : json["materialcolor"].items()) {
//                 if (value.is_string() && value.get<string>().find_first_not_of("0123456789abcdefABCDEF#") == string::npos) {
//                     filtered_colors[key] = value;
//                 }
//             }
//             return filtered_colors.empty() ? nlohmann::json{
//                 {"primary", "#c3c0ff"},
//                 {"onPrimary", "#282377"},
//                 {"primaryContainer", "#3f3c8f"},
//                 {"onPrimaryContainer", "#e2dfff"}
//             } : filtered_colors;
//         } catch (...) {
//             return {
//                 {"primary", "#c3c0ff"},
//                 {"onPrimary", "#282377"},
//                 {"primaryContainer", "#3f3c8f"},
//                 {"onPrimaryContainer", "#e2dfff"}
//             };
//         }
//     }
//     return {
//         {"primary", "#c3c0ff"},
//         {"onPrimary", "#282377"},
//         {"primaryContainer", "#3f3c8f"},
//         {"onPrimaryContainer", "#e2dfff"}
//     };
// }

// int main() {
//     pipe_ptr pipe(popen("cava -p ~/.config/eww/scripts/custom_configs/cava 2>/dev/null", "r"), pclose);
//     if (!pipe) {
//         cerr << "Error: popen() failed for cava" << endl;
//         cout << "{\"bars\": [], \"colors\": {\"primary\": \"#c3c0ff\", \"onPrimary\": \"#282377\", \"primaryContainer\": \"#3f3c8f\", \"onPrimaryContainer\": \"#e2dfff\"}}" << endl;
//         return 1;
//     }
//     file_descriptor_source fd(fileno(pipe.get()), boost::iostreams::never_close_handle);
//     stream<file_descriptor_source> is(fd);
//     string line;
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     nlohmann::json colors = getColors();
//     auto last_color_update = chrono::steady_clock::now();

//     while (getline(is, line)) {
//         auto now = chrono::steady_clock::now();
//         if (chrono::duration_cast<chrono::seconds>(now - last_color_update).count() >= 15) {
//             colors = getColors();
//             last_color_update = now;
//         }
//         cavaToJson(line, colors);
//         cout << line << '\n';
//         cout.flush();
//         sleep_for(milliseconds(50));
//     }
//     return 0;
// }