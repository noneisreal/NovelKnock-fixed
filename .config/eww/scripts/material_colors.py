#!/bin/python3
from material_color_utilities_python import *
from pathlib import Path
import sys
import json
from PIL import Image

DEFAULT_COLOR = "#b5c4ff"

# def safe_hex_from_argb(argb):
#     try:
#         if argb is None:
#             return DEFAULT_COLOR
#         return hexFromArgb(argb)
#     except (TypeError, ValueError):
#         return DEFAULT_COLOR
def safe_hex_from_argb(argb):
    try:
        if argb is None or argb == "" or argb == "null":
            return DEFAULT_COLOR
        return hexFromArgb(argb)
    except (TypeError, ValueError):
        return DEFAULT_COLOR
        
try:
    if len(sys.argv) > 1 and sys.argv[1] == '--path':
        img_path = sys.argv[2]
        if not Path(img_path).is_file():
            raise FileNotFoundError(f"Image not found: {img_path}")
        img = Image.open(img_path)
        basewidth = 64
        wpercent = basewidth / float(img.size[0])
        hsize = int(float(img.size[1]) * wpercent)
        img = img.resize((basewidth, hsize), Image.Resampling.LANCZOS)
        newtheme = themeFromImage(img)
    elif len(sys.argv) > 1 and sys.argv[1] == '--color':
        colorstr = sys.argv[2]
        newtheme = themeFromSourceColor(argbFromHex(colorstr))
    else:
        wallpaper_path = str(Path.home() / '.config/eww/images/wallpaper/wallpaper')
        if not Path(wallpaper_path).is_file():
            raise FileNotFoundError(f"Wallpaper not found: {wallpaper_path}")
        img = Image.open(wallpaper_path)
        basewidth = 64
        wpercent = basewidth / float(img.size[0])
        hsize = int(float(img.size[1]) * wpercent)
        img = img.resize((basewidth, hsize), Image.Resampling.LANCZOS)
        newtheme = themeFromImage(img)
except Exception as e:
    print(f"Error loading image or generating theme: {e}", file=sys.stderr)
    newtheme = themeFromSourceColor(argbFromHex(DEFAULT_COLOR))

colorscheme = newtheme.get('schemes').get('light' if '-l' in sys.argv else 'dark')

colors_dict = {
    "materialcolor": {
        "primary": safe_hex_from_argb(colorscheme.get_primary()),
        "onPrimary": safe_hex_from_argb(colorscheme.get_onPrimary()),
        "primaryContainer": safe_hex_from_argb(colorscheme.get_primaryContainer()),
        "onPrimaryContainer": safe_hex_from_argb(colorscheme.get_onPrimaryContainer()),
        "secondary": safe_hex_from_argb(colorscheme.get_secondary()),
        "onSecondary": safe_hex_from_argb(colorscheme.get_onSecondary()),
        "secondaryContainer": safe_hex_from_argb(colorscheme.get_secondaryContainer()),
        "onSecondaryContainer": safe_hex_from_argb(colorscheme.get_onSecondaryContainer()),
        "tertiary": safe_hex_from_argb(colorscheme.get_tertiary()),
        "onTertiary": safe_hex_from_argb(colorscheme.get_onTertiary()),
        "tertiaryContainer": safe_hex_from_argb(colorscheme.get_tertiaryContainer()),
        "onTertiaryContainer": safe_hex_from_argb(colorscheme.get_onTertiaryContainer()),
        "error": safe_hex_from_argb(colorscheme.get_error()),
        "onError": safe_hex_from_argb(colorscheme.get_onError()),
        "errorContainer": safe_hex_from_argb(colorscheme.get_errorContainer()),
        "onErrorContainer": safe_hex_from_argb(colorscheme.get_onErrorContainer()),
        "background": safe_hex_from_argb(colorscheme.get_background()),
        "onBackground": safe_hex_from_argb(colorscheme.get_onBackground()),
        "surface": safe_hex_from_argb(colorscheme.get_surface()),
        "onSurface": safe_hex_from_argb(colorscheme.get_onSurface()),
        "surfaceVariant": safe_hex_from_argb(colorscheme.get_surfaceVariant()),
        "onSurfaceVariant": safe_hex_from_argb(colorscheme.get_onSurfaceVariant()),
        "outline": safe_hex_from_argb(colorscheme.get_outline()),
        "shadow": safe_hex_from_argb(colorscheme.get_shadow()),
        "inverseSurface": safe_hex_from_argb(colorscheme.get_inverseSurface()),
        "inverseOnSurface": safe_hex_from_argb(colorscheme.get_inverseOnSurface()),
        "inversePrimary": safe_hex_from_argb(colorscheme.get_inversePrimary())
    },
    "image": "null",
    "color": {"source": "Unknown"}
}

print(json.dumps(colors_dict))