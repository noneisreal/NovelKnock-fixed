#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "/usr/include/stb/stb_image.h"

// Convert RGB to hex color string (e.g., "#RRGGBB")
using nlohmann::json;
using std::cout;
using std::ifstream;
using std::string;
using std::min;
using std::max;
using std::ofstream;
using std::to_string;
using std::cerr;

string rgb_to_hex(int r, int g, int b) {
  char hex[8];
  snprintf(hex, sizeof(hex), "#%02x%02x%02x", r, g, b);
  return std::string(hex);
}
// Convert RGB to RGBA string (e.g., "rgba(r,g,b,a)")
string rgb_to_rgba(int r, int g, int b, float a) {
    char rgba[32];
    snprintf(rgba, sizeof(rgba), "rgba(%d,%d,%d,%.2f)", r, g, b, a);
    return string(rgba);
}

// Generate colors from image (simplified: average RGB)
json generate_colors(const string &image_path, const string &url,
                     const string &source) {
  json output;

  // Default JSON matching EWW's expected structure
  output = {
      {"image", "eww_covers/default_cover.png"},
      {"color",
       {{"special", {{"background", "#1c1b1e"}, {"foreground", "#e5e1e6"}}},
        {"colors",
         {{"color0", "#b5c4ff"},
          {"color1", "#b5c4ff"},
          {"color2", "#b5c4ff"},
          {"color3", "#b5c4ff"},
          {"color4", "#b5c4ff"},
          {"color5", "#b5c4ff"},
          {"color6", "#b5c4ff"},
          {"color7", "#b5c4ff"}}},
        {"source", source}}},
      {"materialcolor",
       {{"onPrimaryContainer", "#e2dfff"},
        {"primaryContainer", "#3f3c8f"},
        {"onPrimary", "#282377"},
        {"primary", "#c3c0ff"},
        // {"secondary", "#b2e7ff"},
        // {"onSecondary", "#80b5ea"},
        {"secondaryContainer", "#b2e7ff"},
        {"onSecondaryContainer", "#e3e0f9"},
        {"secondaryContainerRgba", "rgba(181,196,255,0.75)"},
        {"tertiary", "#ebb9d2"}}}};

  ifstream file_check(image_path);
  if(!file_check.good()){
    output["image"] = "eww_covers/default_cover.png";
    return output;
  }
  file_check.close();
  // Load image
  int width, height, channels;
  unsigned char *img =
      stbi_load(image_path.c_str(), &width, &height, &channels, 0);
  if (!img) {
    output["image"] = "eww_covers/default_cover.png"; 
    return output; // Return default on failure
  }

  // Calculate average RGB (placeholder for material_colors.py logic)
  unsigned long r_sum = 0, g_sum = 0, b_sum = 0;
  size_t pixel_count = width * height;
  for (size_t i = 0; i < pixel_count * channels; i += channels) {
    r_sum += img[i];
    g_sum += img[i + 1];
    b_sum += img[i + 2];
  }
  stbi_image_free(img);

  int r = r_sum / pixel_count;
  int g = g_sum / pixel_count;
  int b = b_sum / pixel_count;
      // Generate color0 to color7
    output["color"]["colors"]["color0"] = rgb_to_hex(r, g, b);
    output["color"]["colors"]["color1"] = rgb_to_hex(min(r + 20, 255), min(g + 20, 255), min(b + 20, 255));
    output["color"]["colors"]["color2"] = rgb_to_hex(max(r - 20, 0), max(g - 20, 0), max(b - 20, 0));
    output["color"]["colors"]["color3"] = rgb_to_hex(min(r + 40, 255), min(g + 40, 255), min(b + 40, 255));
    output["color"]["colors"]["color4"] = rgb_to_hex(max(r - 40, 0), max(g - 40, 0), max(b - 40, 0));
    output["color"]["colors"]["color5"] = rgb_to_hex(min(r + 60, 255), min(g + 60, 255), min(b + 60, 255));
    output["color"]["colors"]["color6"] = rgb_to_hex(max(r - 60, 0), max(g - 60, 0), max(b - 60, 0));
    output["color"]["colors"]["color7"] = rgb_to_hex(min(r + 80, 255), min(g + 80, 255), min(b + 80, 255));

    // Update special colors
    output["color"]["special"]["background"] = rgb_to_hex(max(r - 80, 0), max(g - 80, 0), max(b - 80, 0));
    output["color"]["special"]["foreground"] = rgb_to_hex(min(r + 80, 255), min(g + 80, 255), min(b + 80, 255));

  // Update JSON with computed colors (simplified)
    output["image"] = image_path;
    output["materialcolor"]["primary"]                = rgb_to_hex(r, g, b);
    output["materialcolor"]["onPrimary"]              = rgb_to_hex(min(r + 50, 255), min(g + 50, 255), min(b + 50, 255)); // Contrast adjustment
    output["materialcolor"]["primaryContainer"]       = rgb_to_hex(max(r - 50, 0), max(g - 50, 0), max(b - 50, 0));
    output["materialcolor"]["onPrimaryContainer"]     = rgb_to_hex(min(r + 100, 255), min(g + 100, 255), min(b + 100, 255));   
    output["materialcolor"]["secondaryContainer"]     = rgb_to_hex(max( r - 50, 0), max( g - 50, 0), max( b - 50, 0));
    output["materialcolor"]["onSecondaryContainer"]   = rgb_to_hex(min( r + 100, 255), min( g + 100, 255), min( b + 100, 255));
    output["materialcolor"]["secondaryContainerRgba"] = rgb_to_rgba(max(r - 50, 0), max(g - 50, 0), max(b - 50, 0), 0.75);
    output["materialcolor"]["tertiary"]               = rgb_to_hex(max(r - 20, 0), min(g + 20, 255), min(b + 20, 255)); 
    output["color"]["source"] = source;

    // Write SCSS and config files
    ofstream scss_file("./scripts/cache/_colorscheme.colorpallete");
    scss_file << "// Auto generated color theme for image at: " << url << "\n";
    scss_file << "$colorbarbg: " << output["color"]["special"]["background"].get<string>() << ";\n";
    scss_file << "$colorbg: " << rgb_to_rgba(max(r - 80, 0), max(g - 80, 0), max(b - 80, 0), 0.75) << ";\n";
    scss_file << "$colortext: " << output["color"]["special"]["foreground"].get<string>() << ";\n";
    for (int i = 0; i < 8; ++i) {
        scss_file << "$color" << i << ": " << output["color"]["colors"]["color" + to_string(i)].get<string>() << ";\n";
    }
    scss_file.close();

    ofstream conf_file("./scripts/cache/colors_generated.conf");
    conf_file << "# Auto generated color theme for image at: " << url << "\n";
    conf_file << "general {\n";
    conf_file << "    col.active_border = " << rgb_to_rgba(r, g, b, 1.0) << " 45deg\n";
    conf_file << "    col.inactive_border = " << rgb_to_rgba(r, g, b, 0.4) << "\n";
    conf_file << "}\n";
    conf_file.close();

    ofstream icon_file("./scripts/cache/_iconcolor.txt");
    icon_file << output["materialcolor"]["onPrimaryContainer"].get<string>() << "\n";
    icon_file << output["materialcolor"]["tertiary"].get<string>() << "\n";
    icon_file << output["color"]["colors"]["color2"].get<string>() << "\n";
    icon_file << output["color"]["colors"]["color4"].get<string>() << "\n";
    icon_file << output["color"]["colors"]["color5"].get<string>() << "\n";
    icon_file << output["color"]["colors"]["color5"].get<string>() << "\n";
    icon_file.close();

    return output;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
      cerr << "Usage: " << argv[0] << " <image_path> <url> <source>"
           << std::endl;
      // Output default JSON on error
      json default_output = {
          {"image", "eww_covers/default_cover.png"},
          {"color",
           {{"special", {{"background", "#1c1b1e"}, {"foreground", "#e5e1e6"}}},
            {"colors",
             {{"color0", "#b5c4ff"},
              {"color1", "#b5c4ff"},
              {"color2", "#b5c4ff"},
              {"color3", "#b5c4ff"},
              {"color4", "#b5c4ff"},
              {"color5", "#b5c4ff"},
              {"color6", "#b5c4ff"},
              {"color7", "#b5c4ff"}}},
            {"source", "󱛟"}}},
          {"materialcolor",
           {{"onPrimaryContainer", "#e2dfff"},
            {"primaryContainer", "#3f3c8f"},
            {"onPrimary", "#282377"},
            {"primary", "#c3c0ff"},
            // {"secondary", "#b2e7ff"},
            // {"onSecondary", "#80b5ea"},
            {"secondaryContainer", "#282377"},
            {"onSecondaryContainer", "#e3e0f9"},
            {"secondaryContainerRgba", "rgba(181,196,255,0.75)"},
            {"tertiary", "#ebb9d2"}}}};
      cout << default_output.dump() << std::endl;
      return 1;
    }

    string image_path = argv[1];
    string url = argv[2];
    string source = argv[3];

    auto colors = generate_colors(image_path, url, source);
    cout << colors.dump() << std::endl;
    return 0;
}
