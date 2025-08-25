#!/usr/bin/bash
currentshader=$(hyprctl getoption decoration:screen_shader -j | gojq -r '.str')

if [[ "$currentshader" != *"bluefilter.frag" ]]; then
    hyprctl keyword decoration:screen_shader '~/.config/hypr/shaders/bluefilter.frag'
else
    hyprctl keyword decoration:screen_shader ''
    hyprctl reload
fi

scripts/hyprsettings tickle
# #!/usr/bin/bash
# currentshader=$(hyprctl getoption decoration:screen_shader -j | gojq -r '.str')

# if [[ "$currentshader" != *"extradark.frag" ]]; then
#     hyprctl keyword decoration:screen_shader '~/.config/hypr/shaders/extradark.frag'
# else
#     hyprctl keyword decoration:screen_shader ''
#     hyprctl reload
# fi

# scripts/hyprsettings tickle