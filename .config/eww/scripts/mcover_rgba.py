#!/usr/bin/env python3
import sys

def hex_to_rgba(hex_color, opacity=0.75):
    try:
        hex_color = hex_color.lstrip('#')
        if not hex_color or len(hex_color) != 6:
            return f"rgba(255,255,255,{opacity})"
        r = int(hex_color[0:2], 16)
        g = int(hex_color[2:4], 16)
        b = int(hex_color[4:6], 16)
        return f"rgba({r},{g},{b},{opacity})"
    except (ValueError, TypeError):
        return f"rgba(255,255,255,{opacity})"

print(hex_to_rgba(sys.argv[1] if len(sys.argv) > 1 else "#b5c4ff"))
# read a hex from args and convert to rgba
# usage: python mcover_rgba.py #000000
# output: rgba(0, 0, 0, 0.5) // auto 0.5 opacity
# import sys
# 
# hex = sys.argv[1]
# hex = hex.lstrip('#')
# 
# r = int(hex[0:2], 16)
# g = int(hex[2:4], 16)
# b = int(hex[4:6], 16)
# 
# print('rgba(' + str(r) + ', ' + str(g) + ', ' + str(b) + ', 0.5)')
