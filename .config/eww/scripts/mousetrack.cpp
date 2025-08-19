#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using boost::iostreams::file_descriptor_source;
using boost::iostreams::never_close_handle;
using boost::iostreams::stream;
using std::string;
using std::unique_ptr;

using namespace std;

// Terminate existing CAVA processes
void kill_existing_cava() {
    system("pkill -f 'cava -p ~/.config/eww/scripts/custom_configs/cava' 2>/dev/null");
}

void cavaToJson(string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ';')
      s[i] = ',';
  }
  s.pop_back();
}

void cursorPosToJson(string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ';')
      s[i] = ',';
  }
  s.pop_back();
}

string exec(const char* cmd) 
{
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) 
    {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) 
    {
        result += buffer.data();
    }
    return result;
}

int main()
{
    // Kill cava before it exits
    kill_existing_cava();

  unique_ptr<FILE, decltype(&pclose)> pipe(
      popen("cava -p ~/.config/eww/scripts/custom_configs/cava", "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
    file_descriptor_source fd(fileno(pipe.get()), never_close_handle);
    stream<file_descriptor_source> is(fd);
    string line;

    while (std::getline(is, line)) 
    {
        string st = exec("hyprctl cursorpos");
        st.pop_back();
        cout << '[' << st << ']' << endl;
    }
    return 0;
}