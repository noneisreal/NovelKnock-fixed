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
