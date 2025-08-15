![Built for Hyprland](https://img.shields.io/badge/Built%20for-Hyprland-blueviolet?style=flat-square)
![Based on end-4](https://img.shields.io/badge/Based_on-end--4-informational?style=flat-square)

# Fixed "NovelKnock" Dotfiles (Hyprland Edition)

A repaired & repurposed version of [end-4's](https://github.com/end-4/dots-hyprland) dotfiles, 
with minor (and major) tweaks to actually boot and behave nicely.

Tested on EndeavourOS with Hyprland.

## Why?

Because the original configs look gorgeous but are half-broken, and I'm a fan of both aesthetics and sanity.  
So I fixed the NovelKnock. (or i wanted to do something in this summer)

## Features

- Hyprland, Eww, Waybar, Rofi, etc.
- Fixed paths for Hyprland updated 
- Added compatibility with non-end-4 users (aka humans)
- Disable nsfw art 
- not working


## Credits

- Huge thanks to `end-4` for the original inspiration and visual magic.
- Praise be to Jesus for the strength to fix it

## List files
````
.
├── .config
│   ├── eww
│   │   ├── css
│   │   │   ├── _bar.scss
│   │   │   ├── _bottomsheet.scss
│   │   │   ├── _colorscheme_default.scss
│   │   │   ├── _colorscheme.scss
│   │   │   ├── _colors.scss
│   │   │   ├── _dashboard.scss
│   │   │   ├── _iconcolor_default.txt
│   │   │   ├── _iconcolor.txt
│   │   │   ├── _material.scss
│   │   │   ├── _powerview.scss
│   │   │   ├── savedcolors
│   │   │   │   ├── _colorscheme_alive.scss
│   │   │   │   ├── _colorscheme_amaryllis.scss
│   │   │   │   ├── _colorscheme_androidgreen.scss
│   │   │   │   ├── _colorscheme_andromeda.scss
│   │   │   │   ├── _colorscheme_artemis.scss
│   │   │   │   ├── _colorscheme_atermis.scss
│   │   │   │   ├── _colorscheme_avdan.scss
│   │   │   │   ├── _colorscheme_berightthere.scss
│   │   │   │   ├── _colorscheme_bittersweet.scss
│   │   │   │   ├── _colorscheme_blessingbeat.scss
│   │   │   │   ├── _colorscheme_bluegalaxy.scss
│   │   │   │   ├── _colorscheme_bluenation_purple.scss
│   │   │   │   ├── _colorscheme_bluenation.scss
│   │   │   │   ├── _colorscheme_blueroar.scss
│   │   │   │   ├── _colorscheme_breakaway.scss
│   │   │   │   ├── _colorscheme_bunnygirl.scss
│   │   │   │   ├── _colorscheme_bythesunlitwindow.scss
│   │   │   │   ├── _colorscheme_Catppuccin-Mocha.scss
│   │   │   │   ├── _colorscheme_crystalcave.scss
│   │   │   │   ├── _colorscheme_cutelight.scss
│   │   │   │   ├── _colorscheme_cyan.scss
│   │   │   │   ├── _colorscheme_cycles.scss
│   │   │   │   ├── _colorscheme_decoyworld.scss
│   │   │   │   ├── _colorscheme_default.scss
│   │   │   │   ├── _colorscheme_disconnectedblue_dark.scss
│   │   │   │   ├── _colorscheme_disconnectedblue.scss
│   │   │   │   ├── _colorscheme_eclipse.scss
│   │   │   │   ├── _colorscheme_eternalmelody.scss
│   │   │   │   ├── _colorscheme_euphoria.scss
│   │   │   │   ├── _colorscheme_everythinggoeson.scss
│   │   │   │   ├── _colorscheme_finale.scss
│   │   │   │   ├── _colorscheme_finalstep.scss
│   │   │   │   ├── _colorscheme_flare.scss
│   │   │   │   ├── _colorscheme_flate.scss
│   │   │   │   ├── _colorscheme_flowers.scss
│   │   │   │   ├── _colorscheme_forest_bluegreen.scss
│   │   │   │   ├── _colorscheme_forever.scss
│   │   │   │   ├── _colorscheme_forsythia.scss
│   │   │   │   ├── _colorscheme_frozenheart.scss
│   │   │   │   ├── _colorscheme_genshinbeach.scss
│   │   │   │   ├── _colorscheme_godrays.scss
│   │   │   │   ├── _colorscheme_green.scss
│   │   │   │   ├── _colorscheme_ice.scss
│   │   │   │   ├── _colorscheme_innovation.scss
│   │   │   │   ├── _colorscheme_iswear.scss
│   │   │   │   ├── _colorscheme_iwillpickyouup.scss
│   │   │   │   ├── _colorscheme_kurumi.scss
│   │   │   │   ├── _colorscheme_lazertrack.scss
│   │   │   │   ├── _colorscheme_lover.scss
│   │   │   │   ├── _colorscheme_lullaby.scss
│   │   │   │   ├── _colorscheme_meltdown.scss
│   │   │   │   ├── _colorscheme_mirror.scss
│   │   │   │   ├── _colorscheme_monster.scss
│   │   │   │   ├── _colorscheme_moonlight.scss
│   │   │   │   ├── _colorscheme_multi.scss
│   │   │   │   ├── _colorscheme_neon_bluered.scss
│   │   │   │   ├── _colorscheme_notfound.scss
│   │   │   │   ├── _colorscheme_nova.scss
│   │   │   │   ├── _colorscheme_nowthatitstrue.scss
│   │   │   │   ├── _colorscheme_outbreaker.scss
│   │   │   │   ├── _colorscheme_outer.scss
│   │   │   │   ├── _colorscheme_pagoda.scss
│   │   │   │   ├── _colorscheme_piano.scss
│   │   │   │   ├── _colorscheme_purpleplanet.scss
│   │   │   │   ├── _colorscheme_purple.scss
│   │   │   │   ├── _colorscheme_questions.scss
│   │   │   │   ├── _colorscheme_quicksand.scss
│   │   │   │   ├── _colorscheme_raindrops.scss
│   │   │   │   ├── _colorscheme_rebootcode.scss
│   │   │   │   ├── _colorscheme_red_material.scss
│   │   │   │   ├── _colorscheme_red.scss
│   │   │   │   ├── _colorscheme_ripples.scss
│   │   │   │   ├── _colorscheme_running.scss
│   │   │   │   ├── _colorscheme_s73.scss
│   │   │   │   ├── _colorscheme_seethestars.scss
│   │   │   │   ├── _colorscheme_shelter.scss
│   │   │   │   ├── _colorscheme_shiny.scss
│   │   │   │   ├── _colorscheme_something.scss
│   │   │   │   ├── _colorscheme_spacepark.scss
│   │   │   │   ├── _colorscheme_store.scss
│   │   │   │   ├── _colorscheme_stray.scss
│   │   │   │   ├── _colorscheme_thinkingaboutyou.scss
│   │   │   │   ├── _colorscheme_towerofheaven.scss
│   │   │   │   ├── _colorscheme_treecity.scss
│   │   │   │   ├── _colorscheme_ureshii.scss
│   │   │   │   ├── _colorscheme_vacuumtrack.scss
│   │   │   │   ├── _colorscheme_valhalla.scss
│   │   │   │   ├── _colorscheme_vertigo.scss
│   │   │   │   ├── _colorscheme_viking.scss
│   │   │   │   ├── _colorscheme_virtuality_yellow.scss
│   │   │   │   ├── _colorscheme_wayfire.scss
│   │   │   │   ├── _colorscheme_winglow.scss
│   │   │   │   ├── _colorscheme_wontletyougo.scss
│   │   │   │   ├── _colorscheme_yae.scss
│   │   │   │   ├── _colorscheme_zoetrope.scss
│   │   │   │   ├── _iconcolor_alive.txt
│   │   │   │   ├── _iconcolor_amaryllis.txt
│   │   │   │   ├── _iconcolor_androidgreen.txt
│   │   │   │   ├── _iconcolor_andromeda.txt
│   │   │   │   ├── _iconcolor_artemis.txt
│   │   │   │   ├── _iconcolor_atermis.txt
│   │   │   │   ├── _iconcolor_avdan.txt
│   │   │   │   ├── _iconcolor_berightthere.txt
│   │   │   │   ├── _iconcolor_bittersweet.txt
│   │   │   │   ├── _iconcolor_blessingbeat.txt
│   │   │   │   ├── _iconcolor_bluegalaxy.txt
│   │   │   │   ├── _iconcolor_bluenation_purple.txt
│   │   │   │   ├── _iconcolor_bluenation.txt
│   │   │   │   ├── _iconcolor_blueroar.txt
│   │   │   │   ├── _iconcolor_breakaway.txt
│   │   │   │   ├── _iconcolor_bunnygirl.txt
│   │   │   │   ├── _iconcolor_bythesunlitwindow.txt
│   │   │   │   ├── _iconcolor_Catppuccin-Mocha.txt
│   │   │   │   ├── _iconcolor_crystalcave.txt
│   │   │   │   ├── _iconcolor_cutelight.txt
│   │   │   │   ├── _iconcolor_cyan.txt
│   │   │   │   ├── _iconcolor_cycles.txt
│   │   │   │   ├── _iconcolor_decoyworld.txt
│   │   │   │   ├── _iconcolor_default.txt
│   │   │   │   ├── _iconcolor_disconnectedblue_dark.txt
│   │   │   │   ├── _iconcolor_disconnectedblue.txt
│   │   │   │   ├── _iconcolor_eclipse.txt
│   │   │   │   ├── _iconcolor_eternalmelody.txt
│   │   │   │   ├── _iconcolor_euphoria.txt
│   │   │   │   ├── _iconcolor_everythinggoeson.txt
│   │   │   │   ├── _iconcolor_finale.txt
│   │   │   │   ├── _iconcolor_finalstep.txt
│   │   │   │   ├── _iconcolor_flare.txt
│   │   │   │   ├── _iconcolor_flate.txt
│   │   │   │   ├── _iconcolor_flowers.txt
│   │   │   │   ├── _iconcolor_forest_bluegreen.txt
│   │   │   │   ├── _iconcolor_forever.txt
│   │   │   │   ├── _iconcolor_forsythia.txt
│   │   │   │   ├── _iconcolor_frozenheart.txt
│   │   │   │   ├── _iconcolor_genshinbeach.txt
│   │   │   │   ├── _iconcolor_godrays.txt
│   │   │   │   ├── _iconcolor_green.txt
│   │   │   │   ├── _iconcolor_ice.txt
│   │   │   │   ├── _iconcolor_innovation.txt
│   │   │   │   ├── _iconcolor_iswear.txt
│   │   │   │   ├── _iconcolor_iwillpickyouup.txt
│   │   │   │   ├── _iconcolor_kurumi.txt
│   │   │   │   ├── _iconcolor_lazertrack.txt
│   │   │   │   ├── _iconcolor_lover.txt
│   │   │   │   ├── _iconcolor_lullaby.txt
│   │   │   │   ├── _iconcolor_meltdown.txt
│   │   │   │   ├── _iconcolor_mirror.txt
│   │   │   │   ├── _iconcolor_monster.txt
│   │   │   │   ├── _iconcolor_moonlight.txt
│   │   │   │   ├── _iconcolor_multi.txt
│   │   │   │   ├── _iconcolor_neon_bluered.txt
│   │   │   │   ├── _iconcolor_notfound.txt
│   │   │   │   ├── _iconcolor_nova.txt
│   │   │   │   ├── _iconcolor_nowthatitstrue.txt
│   │   │   │   ├── _iconcolor_outbreaker.txt
│   │   │   │   ├── _iconcolor_outer.txt
│   │   │   │   ├── _iconcolor_pagoda.txt
│   │   │   │   ├── _iconcolor_piano.txt
│   │   │   │   ├── _iconcolor_purpleplanet.txt
│   │   │   │   ├── _iconcolor_purple.txt
│   │   │   │   ├── _iconcolor_questions.txt
│   │   │   │   ├── _iconcolor_quicksand.txt
│   │   │   │   ├── _iconcolor_raindrops.txt
│   │   │   │   ├── _iconcolor_rebootcode.txt
│   │   │   │   ├── _iconcolor_red_material.txt
│   │   │   │   ├── _iconcolor_red.txt
│   │   │   │   ├── _iconcolor_ripples.txt
│   │   │   │   ├── _iconcolor_running.txt
│   │   │   │   ├── _iconcolor_s73.txt
│   │   │   │   ├── _iconcolor_seethestars.txt
│   │   │   │   ├── _iconcolor_shelter.txt
│   │   │   │   ├── _iconcolor_shiny.txt
│   │   │   │   ├── _iconcolor_something.txt
│   │   │   │   ├── _iconcolor_spacepark.txt
│   │   │   │   ├── _iconcolor_store.txt
│   │   │   │   ├── _iconcolor_stray.txt
│   │   │   │   ├── _iconcolor_thinkingaboutyou.txt
│   │   │   │   ├── _iconcolor_towerofheaven.txt
│   │   │   │   ├── _iconcolor_treecity.txt
│   │   │   │   ├── _iconcolor_ureshii.txt
│   │   │   │   ├── _iconcolor_vacuumtrack.txt
│   │   │   │   ├── _iconcolor_valhalla.txt
│   │   │   │   ├── _iconcolor_vertigo.txt
│   │   │   │   ├── _iconcolor_viking.txt
│   │   │   │   ├── _iconcolor_virtuality_yellow.txt
│   │   │   │   ├── _iconcolor_wayfire.txt
│   │   │   │   ├── _iconcolor_winglow.txt
│   │   │   │   ├── _iconcolor_wontletyougo.txt
│   │   │   │   ├── _iconcolor_yae.txt
│   │   │   │   ├── _iconcolor_zoetrope.txt
│   │   │   │   ├── _material_alive.scss
│   │   │   │   ├── _material_amaryllis.scss
│   │   │   │   ├── _material_androidgreen.scss
│   │   │   │   ├── _material_avdan.scss
│   │   │   │   ├── _material_berightthere.scss
│   │   │   │   ├── _material_bittersweet.scss
│   │   │   │   ├── _material_blessingbeat.scss
│   │   │   │   ├── _material_bluegalaxy.scss
│   │   │   │   ├── _material_bluenation_purple.scss
│   │   │   │   ├── _material_bluenation.scss
│   │   │   │   ├── _material_blueroar.scss
│   │   │   │   ├── _material_bythesunlitwindow.scss
│   │   │   │   ├── _material_Catppuccin-Mocha.scss
│   │   │   │   ├── _material_crystalcave.scss
│   │   │   │   ├── _material_cutelight.scss
│   │   │   │   ├── _material_cyan.scss
│   │   │   │   ├── _material_default.scss
│   │   │   │   ├── _material_disconnectedblue_dark.scss
│   │   │   │   ├── _material_finale.scss
│   │   │   │   ├── _material_finalstep.scss
│   │   │   │   ├── _material_flare.scss
│   │   │   │   ├── _material_flate.scss
│   │   │   │   ├── _material_flowers.scss
│   │   │   │   ├── _material_forest_bluegreen.scss
│   │   │   │   ├── _material_forever.scss
│   │   │   │   ├── _material_genshinbeach.scss
│   │   │   │   ├── _material_godrays.scss
│   │   │   │   ├── _material_green.scss
│   │   │   │   ├── _material_iwillpickyouup.scss
│   │   │   │   ├── _material_lover.scss
│   │   │   │   ├── _material_meltdown.scss
│   │   │   │   ├── _material_mirror.scss
│   │   │   │   ├── _material_moonlight.scss
│   │   │   │   ├── _material_neon_bluered.scss
│   │   │   │   ├── _material_nova.scss
│   │   │   │   ├── _material_outbreaker.scss
│   │   │   │   ├── _material_outer.scss
│   │   │   │   ├── _material_pagoda.scss
│   │   │   │   ├── _material_purple.scss
│   │   │   │   ├── _material_questions.scss
│   │   │   │   ├── _material_quicksand.scss
│   │   │   │   ├── _material_raindrops.scss
│   │   │   │   ├── _material_rebootcode.scss
│   │   │   │   ├── _material_red_material.scss
│   │   │   │   ├── _material_ripples.scss
│   │   │   │   ├── _material_running.scss
│   │   │   │   ├── _material_seethestars.scss
│   │   │   │   ├── _material_shelter.scss
│   │   │   │   ├── _material_spacepark.scss
│   │   │   │   ├── _material_store.scss
│   │   │   │   ├── _material_stray.scss
│   │   │   │   ├── _material_treecity.scss
│   │   │   │   ├── _material_vacuumtrack.scss
│   │   │   │   ├── _material_virtuality_yellow.scss
│   │   │   │   ├── _material_winglow.scss
│   │   │   │   └── _material_zoetrope.scss
│   │   │   ├── _sidebar.scss
│   │   │   └── _supercontext.scss
│   │   ├── eww_covers
│   │   │   ├── cover_art
│   │   │   ├── cover_art_error
│   │   │   ├── cover_art_other
│   │   │   ├── cover_art_yt
│   │   │   ├── waifu_loading
│   │   │   └── waifu_temp
│   │   ├── eww.scss
│   │   ├── eww.yuck
│   │   ├── images
│   │   │   ├── icons
│   │   │   │   ├── discord.png
│   │   │   │   ├── distros
│   │   │   │   │   └── EndeavourOS
│   │   │   │   ├── github.svg
│   │   │   │   ├── lazer_icons
│   │   │   │   │   ├── beatmaps.png
│   │   │   │   │   ├── changelog.png
│   │   │   │   │   ├── dashboard_hover.png
│   │   │   │   │   ├── dashboard.png
│   │   │   │   │   ├── forum.png
│   │   │   │   │   ├── music_hover.png
│   │   │   │   │   ├── music_hover_reference.png
│   │   │   │   │   ├── music.png
│   │   │   │   │   ├── music_reference.png
│   │   │   │   │   ├── news.png
│   │   │   │   │   ├── notifications_hover.png
│   │   │   │   │   ├── notifications.png
│   │   │   │   │   ├── options_hover.png
│   │   │   │   │   ├── options.png
│   │   │   │   │   ├── rankings.png
│   │   │   │   │   ├── transparent
│   │   │   │   │   │   ├── beatmappacks.png
│   │   │   │   │   │   ├── beatmaps.png
│   │   │   │   │   │   ├── changelog.png
│   │   │   │   │   │   ├── chat.png
│   │   │   │   │   │   ├── contests.png
│   │   │   │   │   │   ├── forum.png
│   │   │   │   │   │   ├── home.png
│   │   │   │   │   │   ├── news.png
│   │   │   │   │   │   ├── rankings.png
│   │   │   │   │   │   ├── search.png
│   │   │   │   │   │   ├── settings.png
│   │   │   │   │   │   ├── store.png
│   │   │   │   │   │   ├── tournaments.png
│   │   │   │   │   │   └── wiki.png
│   │   │   │   │   └── wiki.png
│   │   │   │   ├── reddit.svg
│   │   │   │   ├── win-clicked.png
│   │   │   │   ├── win-inactive.png
│   │   │   │   ├── winnews-clicked.png
│   │   │   │   ├── winnews.png
│   │   │   │   ├── win.png
│   │   │   │   ├── wintaskview-clicked.png
│   │   │   │   └── wintaskview.png
│   │   │   ├── menus
│   │   │   │   ├── btn0.svg
│   │   │   │   ├── btn1.svg
│   │   │   │   ├── btn2.svg
│   │   │   │   ├── btn3.svg
│   │   │   │   ├── btn4.svg
│   │   │   │   ├── corner_bottomleft.svg
│   │   │   │   ├── corner_bottomright.svg
│   │   │   │   ├── corner_topleft.svg
│   │   │   │   ├── corner_topright.svg
│   │   │   │   └── radial.svg
│   │   │   ├── pictures
│   │   │   │   ├── banner_left
│   │   │   │   ├── banner_right
│   │   │   │   └── qr_aur.png
│   │   │   ├── svg
│   │   │   │   ├── app.svg
│   │   │   │   └── dark
│   │   │   │       └── app.svg
│   │   │   ├── textures
│   │   │   │   └── acrylic.png
│   │   │   └── wallpaper
│   │   │       ├── patch.txt
│   │   │       └── wallpaper.png
│   │   ├── json
│   │   │   ├── directories.json
│   │   │   ├── langs.json
│   │   │   ├── taskbar.json
│   │   │   ├── todo.json
│   │   │   └── websites.json
│   │   ├── kitty
│   │   │   └── kitty.conf
│   │   ├── modules
│   │   │   ├── colorscheme.yuck
│   │   │   ├── dynamicleft.yuck
│   │   │   ├── dynamicright.yuck
│   │   │   ├── music.yuck
│   │   │   ├── notifications.yuck
│   │   │   ├── osd_bright.yuck
│   │   │   ├── osd_volume.yuck
│   │   │   ├── sysinfo.yuck
│   │   │   ├── system.yuck
│   │   │   ├── taskbar.yuck
│   │   │   └── workspaces.yuck
│   │   ├── scripts
│   │   │   ├── activewin
│   │   │   ├── activews
│   │   │   ├── airplane
│   │   │   ├── allappnames
│   │   │   ├── allappnames.cpp
│   │   │   ├── allapps
│   │   │   ├── allapps.cpp
│   │   │   ├── applycolor
│   │   │   ├── appsearch_bash
│   │   │   ├── appsearch.cpp
│   │   │   ├── audioapps
│   │   │   ├── audioapps.cpp
│   │   │   ├── audiolevels
│   │   │   ├── battery
│   │   │   ├── bluetooth
│   │   │   ├── brightness
│   │   │   ├── build
│   │   │   │   └── Debug
│   │   │   │       ├── appsearch.o
│   │   │   │       ├── cavajson.o
│   │   │   │       ├── outDebug
│   │   │   │       └── taskviewlayout.o
│   │   │   ├── cache
│   │   │   │   ├── accessories-calculator
│   │   │   │   ├── applications-system-symbolic
│   │   │   │   ├── arandr
│   │   │   │   ├── ark
│   │   │   │   ├── assistant
│   │   │   │   ├── battery
│   │   │   │   ├── bluetooth
│   │   │   │   ├── btop
│   │   │   │   ├── chromium-browser
│   │   │   │   ├── CMakeSetup
│   │   │   │   ├── cmus
│   │   │   │   ├── code-oss
│   │   │   │   ├── _colorscheme.colorpallete
│   │   │   │   ├── colors_generated.conf
│   │   │   │   ├── com.github.neithern.g4music
│   │   │   │   ├── com.obsproject.Studio
│   │   │   │   ├── compton
│   │   │   │   ├── com.visualstudio.code.oss
│   │   │   │   ├── designer
│   │   │   │   ├── dialog-password
│   │   │   │   ├── discord
│   │   │   │   ├── Discord
│   │   │   │   ├── display
│   │   │   │   ├── dunst-history.json
│   │   │   │   ├── dunst-lock-info
│   │   │   │   ├── Electron
│   │   │   │   ├── electron27
│   │   │   │   ├── electron35
│   │   │   │   ├── electron36
│   │   │   │   ├── electron37
│   │   │   │   ├── emblem-music-symbolic
│   │   │   │   ├── endeavouros-icon
│   │   │   │   ├── entries.txt
│   │   │   │   ├── entrynames.txt
│   │   │   │   ├── eww
│   │   │   │   ├── Eww
│   │   │   │   ├── fcitx
│   │   │   │   ├── firefox
│   │   │   │   ├── firewall-config
│   │   │   │   ├── fish
│   │   │   │   ├── gammastep
│   │   │   │   ├── get-hot-new-stuff
│   │   │   │   ├── google-chrome
│   │   │   │   ├── Google-chrome
│   │   │   │   ├── gvim
│   │   │   │   ├── gwenview
│   │   │   │   ├── haruna
│   │   │   │   ├── htop
│   │   │   │   ├── hwinfo
│   │   │   │   ├── hwloc
│   │   │   │   ├── _iconcolor.txt
│   │   │   │   ├── input-keyboard
│   │   │   │   ├── input-keyboard-virtual
│   │   │   │   ├── io.elementary.granite-7
│   │   │   │   ├── java24-openjdk
│   │   │   │   ├── kate
│   │   │   │   ├── kde
│   │   │   │   ├── kdeconnect
│   │   │   │   ├── kde-frameworks
│   │   │   │   ├── kew
│   │   │   │   ├── kfontview
│   │   │   │   ├── kitty
│   │   │   │   ├── klipper
│   │   │   │   ├── kmenuedit
│   │   │   │   ├── knetattach
│   │   │   │   ├── krunner
│   │   │   │   ├── ktip
│   │   │   │   ├── kwalletmanager
│   │   │   │   ├── kwrite
│   │   │   │   ├── linguist
│   │   │   │   ├── map-globe
│   │   │   │   ├── mark-location-symbolic
│   │   │   │   ├── _material.colorpallete
│   │   │   │   ├── mpv
│   │   │   │   ├── multimedia-volume-control
│   │   │   │   ├── net.log
│   │   │   │   ├── network-vpn
│   │   │   │   ├── network-wired
│   │   │   │   ├── network-wireless-hotspot
│   │   │   │   ├── network-wireless-symbolic
│   │   │   │   ├── nitrogen
│   │   │   │   ├── nm-connection-editor
│   │   │   │   ├── nvim
│   │   │   │   ├── okular
│   │   │   │   ├── org.fcitx.fcitx5-config-qt
│   │   │   │   ├── org.fontforge.FontForge
│   │   │   │   ├── org.gnome.Meld
│   │   │   │   ├── org.gnome.TextEditor
│   │   │   │   ├── org.kde.dolphin
│   │   │   │   ├── org.kde.gwenview
│   │   │   │   ├── org.kde.kate
│   │   │   │   ├── org.kde.okular
│   │   │   │   ├── org.kde.plasma-systemmonitor
│   │   │   │   ├── org.pipewire.Helvum
│   │   │   │   ├── org.quickshell
│   │   │   │   ├── org.upscayl.Upscayl
│   │   │   │   ├── pinentry
│   │   │   │   ├── plasma
│   │   │   │   ├── plasma-browser-integration
│   │   │   │   ├── plasma-search
│   │   │   │   ├── plasmashell
│   │   │   │   ├── preferences-desktop
│   │   │   │   ├── preferences-desktop-accessibility
│   │   │   │   ├── preferences-desktop-activities
│   │   │   │   ├── preferences-desktop-animations
│   │   │   │   ├── preferences-desktop-baloo
│   │   │   │   ├── preferences-desktop-color
│   │   │   │   ├── preferences-desktop-cursors
│   │   │   │   ├── preferences-desktop-default-applications
│   │   │   │   ├── preferences-desktop-display-color
│   │   │   │   ├── preferences-desktop-display-randr
│   │   │   │   ├── preferences-desktop-effects
│   │   │   │   ├── preferences-desktop-emoticons
│   │   │   │   ├── preferences-desktop-feedback
│   │   │   │   ├── preferences-desktop-filetype-association
│   │   │   │   ├── preferences-desktop-font
│   │   │   │   ├── preferences-desktop-font-installer
│   │   │   │   ├── preferences-desktop-gaming
│   │   │   │   ├── preferences-desktop-icons
│   │   │   │   ├── preferences-desktop-keyboard
│   │   │   │   ├── preferences-desktop-keyboard-shortcut
│   │   │   │   ├── preferences-desktop-locale
│   │   │   │   ├── preferences-desktop-mouse
│   │   │   │   ├── preferences-desktop-notification-bell
│   │   │   │   ├── preferences-desktop-plasma-theme
│   │   │   │   ├── preferences-desktop-sound
│   │   │   │   ├── preferences-desktop-tablet
│   │   │   │   ├── preferences-desktop-theme
│   │   │   │   ├── preferences-desktop-theme-applications
│   │   │   │   ├── preferences-desktop-theme-global
│   │   │   │   ├── preferences-desktop-theme-windowdecorations
│   │   │   │   ├── preferences-desktop-touchpad
│   │   │   │   ├── preferences-desktop-touchscreen
│   │   │   │   ├── preferences-desktop-user-password
│   │   │   │   ├── preferences-desktop-virtual
│   │   │   │   ├── preferences-desktop-wallpaper
│   │   │   │   ├── preferences-devices-printer
│   │   │   │   ├── preferences-kde-connect
│   │   │   │   ├── preferences-online-accounts
│   │   │   │   ├── preferences-security-firewall
│   │   │   │   ├── preferences-smart-status
│   │   │   │   ├── preferences-system
│   │   │   │   ├── preferences-system-bluetooth
│   │   │   │   ├── preferences-system-login
│   │   │   │   ├── preferences-system-network
│   │   │   │   ├── preferences-system-network-connection
│   │   │   │   ├── preferences-system-network-proxy
│   │   │   │   ├── preferences-system-power-management
│   │   │   │   ├── preferences-system-session-services
│   │   │   │   ├── preferences-system-splash
│   │   │   │   ├── preferences-system-tabbox
│   │   │   │   ├── preferences-system-time
│   │   │   │   ├── preferences-system-users
│   │   │   │   ├── preferences-system-windows
│   │   │   │   ├── preferences-system-windows-actions
│   │   │   │   ├── preferences-web-browser-shortcuts
│   │   │   │   ├── printer
│   │   │   │   ├── qdbusviewer
│   │   │   │   ├── qemu
│   │   │   │   ├── qv4l2
│   │   │   │   ├── qvidcap
│   │   │   │   ├── redshift-status-on
│   │   │   │   ├── rofi
│   │   │   │   ├── security-medium
│   │   │   │   ├── smartphone
│   │   │   │   ├── spectacle
│   │   │   │   ├── Spotify
│   │   │   │   ├── spotify-client
│   │   │   │   ├── stoken-gui
│   │   │   │   ├── swappy
│   │   │   │   ├── system-file-manager
│   │   │   │   ├── system-log-out
│   │   │   │   ├── system-run
│   │   │   │   ├── systemsettings
│   │   │   │   ├── system-software-install
│   │   │   │   ├── tools-check-spelling
│   │   │   │   ├── tools-report-bug
│   │   │   │   ├── user-trash
│   │   │   │   ├── utilities-system-monitor
│   │   │   │   ├── utilities-terminal
│   │   │   │   ├── virt-manager
│   │   │   │   ├── virt-viewer
│   │   │   │   ├── vlc
│   │   │   │   ├── wps-office2019-etmain
│   │   │   │   ├── wps-office2019-kprometheus
│   │   │   │   ├── wps-office2019-pdfmain
│   │   │   │   ├── wps-office2019-wppmain
│   │   │   │   ├── wps-office2019-wpsmain
│   │   │   │   ├── xorg
│   │   │   │   ├── yad
│   │   │   │   ├── zen
│   │   │   │   ├── zen-bin
│   │   │   │   └── zen-browser
│   │   │   ├── calendarlayout
│   │   │   ├── calendarlayout.cpp
│   │   │   ├── cavajson
│   │   │   ├── cavajson.cpp
│   │   │   ├── checkcjk
│   │   │   ├── colorgen
│   │   │   ├── colorgen.bak
│   │   │   ├── colormanage
│   │   │   ├── custom_configs
│   │   │   │   ├── cava
│   │   │   │   └── waybar-tray-config
│   │   │   │       ├── config
│   │   │   │       └── style.css
│   │   │   ├── dashactivate
│   │   │   ├── dumptows.cpp
│   │   │   ├── editmode.sh
│   │   │   ├── focuswindow
│   │   │   ├── getfirstdayofmonth
│   │   │   ├── get_open_icons
│   │   │   ├── get_open_icons.bak
│   │   │   ├── hyprsettings
│   │   │   ├── hyprtest
│   │   │   ├── hyprview.sh
│   │   │   ├── iconpatch
│   │   │   ├── isopen.sh
│   │   │   ├── language.cpp
│   │   │   ├── launchapp
│   │   │   ├── limitlen.py
│   │   │   ├── listentries.py
│   │   │   ├── listentrynames.py
│   │   │   ├── material_colors.bak
│   │   │   ├── material_colors.py
│   │   │   ├── mcover_rgba.py
│   │   │   ├── memory.sh
│   │   │   ├── mousetrack.cpp
│   │   │   ├── music
│   │   │   ├── net
│   │   │   ├── notifget
│   │   │   ├── notifget.cpp
│   │   │   ├── notification-on-receive.sh
│   │   │   ├── notifications
│   │   │   ├── notify-receive
│   │   │   │   ├── Cargo.lock
│   │   │   │   ├── Cargo.toml
│   │   │   │   └── src
│   │   │   │       ├── dbus.rs
│   │   │   │       └── main.rs
│   │   │   ├── open-blurred.sh
│   │   │   ├── overview
│   │   │   ├── overview1
│   │   │   ├── overview2
│   │   │   ├── overview.cpp
│   │   │   ├── overview-thumbnails
│   │   │   ├── overview-wrapper
│   │   │   ├── overview-wrapper1
│   │   │   ├── overview-wrapper2
│   │   │   ├── scroll-dynamicleft-module
│   │   │   ├── scroll-dynamicright-module
│   │   │   ├── scroll-gallery
│   │   │   ├── scrollmonth
│   │   │   ├── scroll-quote
│   │   │   ├── scroll-settings
│   │   │   ├── scroll-sideleft-favourite
│   │   │   ├── scroll-waifu
│   │   │   ├── search_items.txt
│   │   │   ├── selectwindow
│   │   │   ├── supersecretsettings
│   │   │   │   ├── culture
│   │   │   │   ├── culture.mp3
│   │   │   │   └── doreload
│   │   │   ├── swapws
│   │   │   ├── swapws.cpp
│   │   │   ├── switchwall
│   │   │   ├── taskbar.cpp
│   │   │   ├── taskbarloop
│   │   │   ├── taskviewlayout.cpp
│   │   │   ├── taskviewlayout-wrapper
│   │   │   ├── todo.cpp
│   │   │   ├── toggle-bottomsheet.sh
│   │   │   ├── toggle-dashboard.sh
│   │   │   ├── togglelight
│   │   │   ├── toggle-nightlight.sh
│   │   │   ├── toggle-osd-bright.sh
│   │   │   ├── toggle-osd-vol.sh
│   │   │   ├── toggle-overview.sh
│   │   │   ├── toggle-powerview.sh
│   │   │   ├── toggle-sideleft.sh
│   │   │   ├── toggle-sideright.sh
│   │   │   ├── toggle-supercontext.sh
│   │   │   ├── update-tray.sh
│   │   │   ├── volume
│   │   │   ├── volume.bak
│   │   │   ├── waifu-get.py
│   │   │   ├── waifupics.py
│   │   │   ├── winlist
│   │   │   ├── winnumbers
│   │   │   ├── workdir
│   │   │   │   ├── __mode_colors.txt
│   │   │   │   └── __mode_light_dark.txt
│   │   │   └── workspaces
│   │   ├── variables.yuck
│   │   ├── .vscode
│   │   │   ├── c_cpp_properties.json
│   │   │   ├── extensions.json
│   │   │   ├── launch.json
│   │   │   ├── settings.json
│   │   │   └── tasks.json
│   │   └── windows
│   │       ├── bgdecor.yuck
│   │       ├── bottomsheet.yuck
│   │       ├── dashboard.yuck
│   │       ├── powerview.yuck
│   │       ├── sideleft.yuck
│   │       ├── sideleft.yuck.bak
│   │       ├── sideright.yuck
│   │       ├── sideright.yuck.bak
│   │       └── supercontext.yuck
│   ├── gtk-3.0
│   │   ├── assets
│   │   │   ├── close-active.svg
│   │   │   ├── close-backdrop-active.svg
│   │   │   ├── close-backdrop-hover.svg
│   │   │   ├── close-backdrop-normal.svg
│   │   │   ├── close-hover.svg
│   │   │   ├── close-normal.svg
│   │   │   ├── maximize-active.svg
│   │   │   ├── maximize-backdrop-active.svg
│   │   │   ├── maximize-backdrop-hover.svg
│   │   │   ├── maximize-backdrop-normal.svg
│   │   │   ├── maximized-active.svg
│   │   │   ├── maximized-backdrop-active.svg
│   │   │   ├── maximized-backdrop-hover.svg
│   │   │   ├── maximized-backdrop-normal.svg
│   │   │   ├── maximized-hover.svg
│   │   │   ├── maximized-normal.svg
│   │   │   ├── maximize-hover.svg
│   │   │   ├── maximize-normal.svg
│   │   │   ├── minimize-active.svg
│   │   │   ├── minimize-backdrop-active.svg
│   │   │   ├── minimize-backdrop-hover.svg
│   │   │   ├── minimize-backdrop-normal.svg
│   │   │   ├── minimize-hover.svg
│   │   │   └── minimize-normal.svg
│   │   ├── colors.css
│   │   ├── gtk.css
│   │   ├── settings.ini
│   │   └── window_decorations.css
│   ├── gtk-4.0
│   │   ├── assets
│   │   ├── colors.css
│   │   ├── gtk.css
│   │   ├── settings.ini
│   │   └── window_decorations.css
│   ├── gtklock
│   │   ├── config.ini
│   │   └── style.css
│   ├── hypr
│   │   ├── colors.conf
│   │   ├── colors_default.conf
│   │   ├── dirs
│   │   │   ├── hyprland_HORIZONTAL.conf
│   │   │   ├── hyprland_VERTICAL.conf
│   │   │   ├── keybinds_HORIZONTAL.conf
│   │   │   └── keybinds_VERTICAL.conf
│   │   ├── env.conf
│   │   ├── execs.conf
│   │   ├── hypr.conf
│   │   ├── hyprland.conf
│   │   ├── keybinds.conf
│   │   ├── savedcolors
│   │   │   ├── colors_alive.conf
│   │   │   ├── colors_alpha.conf
│   │   │   ├── colors_amaryllis.conf
│   │   │   ├── colors_androidgreen.conf
│   │   │   ├── colors_andromeda.conf
│   │   │   ├── colors_artemis.conf
│   │   │   ├── colors_atermis.conf
│   │   │   ├── colors_avdan.conf
│   │   │   ├── colors_beach.conf
│   │   │   ├── colors_berightthere.conf
│   │   │   ├── colors_bittersweet.conf
│   │   │   ├── colors_blessingbeat.conf
│   │   │   ├── colors_bluegalaxy.conf
│   │   │   ├── colors_bluenation.conf
│   │   │   ├── colors_bluenation_purple.conf
│   │   │   ├── colors_blueroar.conf
│   │   │   ├── colors_breakaway.conf
│   │   │   ├── colors_bunnygirl.conf
│   │   │   ├── colors_bythesunlitwindow.conf
│   │   │   ├── colors_crystalcave.conf
│   │   │   ├── colors_cutelight.conf
│   │   │   ├── colors_cyan.conf
│   │   │   ├── colors_cycles.conf
│   │   │   ├── colors_decoyworld.conf
│   │   │   ├── colors_default.conf
│   │   │   ├── colors_disconnectedblue.conf
│   │   │   ├── colors_disconnectedblue_dark.conf
│   │   │   ├── colors_eclipse.conf
│   │   │   ├── colors_eternalmelody.conf
│   │   │   ├── colors_euphoria.conf
│   │   │   ├── colors_everythinggoeson.conf
│   │   │   ├── colors_finale.conf
│   │   │   ├── colors_finalstep.conf
│   │   │   ├── colors_flare.conf
│   │   │   ├── colors_flate.conf
│   │   │   ├── colors_flowers.conf
│   │   │   ├── colors_forest_bluegreen.conf
│   │   │   ├── colors_forever.conf
│   │   │   ├── colors_forsythia.conf
│   │   │   ├── colors_frostdragon.conf
│   │   │   ├── colors_frozenheart.conf
│   │   │   ├── colors_genshinbeach.conf
│   │   │   ├── colors_godrays.conf
│   │   │   ├── colors_green.conf
│   │   │   ├── colors_heartafire.conf
│   │   │   ├── colors_ice.conf
│   │   │   ├── colors_innovation.conf
│   │   │   ├── colors_iswear.conf
│   │   │   ├── colors_iwillpickyouup.conf
│   │   │   ├── colors_kurumi.conf
│   │   │   ├── colors_lazertrack.conf
│   │   │   ├── colors_lover.conf
│   │   │   ├── colors_lullaby.conf
│   │   │   ├── colors_meltdown.conf
│   │   │   ├── colors_mirror.conf
│   │   │   ├── colors_moments.conf
│   │   │   ├── colors_monster.conf
│   │   │   ├── colors_moonlight.conf
│   │   │   ├── colors_multi.conf
│   │   │   ├── colors_neon_bluered.conf
│   │   │   ├── colors_notfound.conf
│   │   │   ├── colors_nova.conf
│   │   │   ├── colors_nowthatitstrue.conf
│   │   │   ├── colors_osubluegreen.conf
│   │   │   ├── colors_outbreaker.conf
│   │   │   ├── colors_outer.conf
│   │   │   ├── colors_pagoda.conf
│   │   │   ├── colors_piano.conf
│   │   │   ├── colors_purple.conf
│   │   │   ├── colors_purpleplanet.conf
│   │   │   ├── colors_questions.conf
│   │   │   ├── colors_quicksand.conf
│   │   │   ├── colors_raindrops.conf
│   │   │   ├── colors_rebootcode.conf
│   │   │   ├── colors_red.conf
│   │   │   ├── colors_red_material.conf
│   │   │   ├── colors_ripples.conf
│   │   │   ├── colors_running.conf
│   │   │   ├── colors_s73.conf
│   │   │   ├── colors_seethestars.conf
│   │   │   ├── colors_shelter.conf
│   │   │   ├── colors_shiny.conf
│   │   │   ├── colors_skylightz.conf
│   │   │   ├── colors_something.conf
│   │   │   ├── colors_space.conf
│   │   │   ├── colors_spacepark.conf
│   │   │   ├── colors_store.conf
│   │   │   ├── colors_stray.conf
│   │   │   ├── colors_summer-gruv.conf
│   │   │   ├── colors_thinkingaboutyou.conf
│   │   │   ├── colors_towerofheaven.conf
│   │   │   ├── colors_treecity.conf
│   │   │   ├── colors_ureshii.conf
│   │   │   ├── colors_vacuumtrack.conf
│   │   │   ├── colors_valhalla.conf
│   │   │   ├── colors_vertigo.conf
│   │   │   ├── colors_viking.conf
│   │   │   ├── colors_virtuality_yellow.conf
│   │   │   ├── colors_wayfire.conf
│   │   │   ├── colors_winglow.conf
│   │   │   ├── colors_wontletyougo.conf
│   │   │   ├── colors_yae.conf
│   │   │   └── colors_zoetrope.conf
│   │   ├── shaders
│   │   │   ├── bluefilter.frag
│   │   │   ├── blur.frag
│   │   │   ├── crt.frag
│   │   │   ├── drugs.frag
│   │   │   ├── extradark.frag
│   │   │   ├── nothing.frag
│   │   │   └── solarized.frag
│   │   └── windowrules.conf
│   ├── kitty
│   │   └── kitty.conf
│   ├── starship.toml
│   └── waybar
│       ├── config
│       ├── noise.png
│       ├── style.css
│       └── win.png
├── Import Manually
│   ├── chromethemes
│   │   ├── Chrome-catppuccin-mocha-Colorful
│   │   │   ├── Cached Theme.pak
│   │   │   ├── images
│   │   │   │   ├── icon128.png
│   │   │   │   ├── icon16.png
│   │   │   │   └── icon48.png
│   │   │   └── manifest.json
│   │   ├── EverForest-Dark-B
│   │   │   ├── Cached Theme.pak
│   │   │   ├── images
│   │   │   │   ├── icon128.png
│   │   │   │   ├── icon16.png
│   │   │   │   └── icon48.png
│   │   │   └── manifest.json
│   │   ├── README.md
│   │   └── TokyoNight
│   │       ├── Cached Theme.pak
│   │       ├── images
│   │       │   ├── icon128.png
│   │       │   ├── icon16.png
│   │       │   └── icon48.png
│   │       └── manifest.json
│   ├── execs (add to path)
│   │   ├── lock.sh
│   │   ├── record-script.sh
│   │   └── wofi-emoji
│   ├── firefox
│   │   └── GNOME_red
│   │       ├── theme
│   │       │   ├── colors
│   │       │   │   ├── dark.css
│   │       │   │   ├── dark-maia.css
│   │       │   │   ├── light.css
│   │       │   │   └── light-maia.css
│   │       │   ├── extensions
│   │       │   │   └── tab-center-reborn.css
│   │       │   ├── gnome-theme.css
│   │       │   ├── icons
│   │       │   │   ├── applications-engineering-symbolic.svg
│   │       │   │   ├── application-x-addon-symbolic.svg
│   │       │   │   ├── audio-muted-symbolic.svg
│   │       │   │   ├── audio-playing-symbolic.svg
│   │       │   │   ├── bullet-symbolic.svg
│   │       │   │   ├── edit-clear-symbolic.svg
│   │       │   │   ├── edit-copy-symbolic.svg
│   │       │   │   ├── edit-cut-symbolic.svg
│   │       │   │   ├── edit-find-symbolic.svg
│   │       │   │   ├── edit-paste-symbolic.svg
│   │       │   │   ├── eye-not-looking-symbolic.svg
│   │       │   │   ├── firefox-symbolic.svg
│   │       │   │   ├── folder-download-symbolic.svg
│   │       │   │   ├── folder-symbolic.svg
│   │       │   │   ├── general-properties-symbolic.svg
│   │       │   │   ├── go-down-symbolic.svg
│   │       │   │   ├── go-next-symbolic.svg
│   │       │   │   ├── go-previous-symbolic.svg
│   │       │   │   ├── go-up-symbolic.svg
│   │       │   │   ├── info-symbolic.svg
│   │       │   │   ├── key-symbolic.svg
│   │       │   │   ├── list-add-symbolic.svg
│   │       │   │   ├── mail-unread-symbolic.svg
│   │       │   │   ├── message-symbolic.svg
│   │       │   │   ├── non-starred-symbolic.svg
│   │       │   │   ├── open-menu-symbolic.svg
│   │       │   │   ├── padlock-insecure-symbolic.svg
│   │       │   │   ├── padlock-symbolic.svg
│   │       │   │   ├── pan-down-symbolic.svg
│   │       │   │   ├── pan-end-symbolic.svg
│   │       │   │   ├── pan-start-symbolic.svg
│   │       │   │   ├── pan-up-symbolic.svg
│   │       │   │   ├── play-large-disabled-symbolic.svg
│   │       │   │   ├── preferences-system-symbolic.svg
│   │       │   │   ├── preferences-system-time-symbolic.svg
│   │       │   │   ├── printer-symbolic.svg
│   │       │   │   ├── process-stop-symbolic.svg
│   │       │   │   ├── process-working-symbolic-black.svg
│   │       │   │   ├── process-working-symbolic.svg
│   │       │   │   ├── reader-mode-symbolic.svg
│   │       │   │   ├── security-high-symbolic.svg
│   │       │   │   ├── security-low-symbolic.svg
│   │       │   │   ├── select-symbolic.svg
│   │       │   │   ├── settings-symbolic.svg
│   │       │   │   ├── starred-symbolic.svg
│   │       │   │   ├── tab-new-symbolic.svg
│   │       │   │   ├── tab-symbolic.svg
│   │       │   │   ├── toggle-right-sidebar-symbolic.svg
│   │       │   │   ├── toggle-sidebar-symbolic.svg
│   │       │   │   ├── user-home-symbolic.svg
│   │       │   │   ├── view-fullscreen-symbolic.svg
│   │       │   │   ├── view-more-horizontal-symbolic.svg
│   │       │   │   ├── view-refresh-symbolic.svg
│   │       │   │   ├── view-restore-symbolic.svg
│   │       │   │   ├── window-close-symbolic.svg
│   │       │   │   ├── window-maximize-symbolic.svg
│   │       │   │   ├── window-minimize-symbolic.svg
│   │       │   │   ├── window-new-symbolic.svg
│   │       │   │   ├── window-restore-symbolic.svg
│   │       │   │   ├── zoom-in-symbolic.svg
│   │       │   │   └── zoom-out-symbolic.svg
│   │       │   ├── pages
│   │       │   │   ├── newtab.css
│   │       │   │   └── privatebrowsing.css
│   │       │   ├── parts
│   │       │   │   ├── buttons.css
│   │       │   │   ├── buttons-fixes.css
│   │       │   │   ├── controls.css
│   │       │   │   ├── csd.css
│   │       │   │   ├── dialogs.css
│   │       │   │   ├── entries.css
│   │       │   │   ├── findbar.css
│   │       │   │   ├── headerbar.css
│   │       │   │   ├── headerbar-private-window.css
│   │       │   │   ├── icons.css
│   │       │   │   ├── lists.css
│   │       │   │   ├── popups-contents.css
│   │       │   │   ├── popups.css
│   │       │   │   ├── remove-white-flash.css
│   │       │   │   ├── sidebar.css
│   │       │   │   ├── tabsbar.css
│   │       │   │   ├── toolbox.css
│   │       │   │   ├── urlbar.css
│   │       │   │   └── video-player.css
│   │       │   ├── symbolic-tab-icons.css
│   │       │   └── system-icons.css
│   │       ├── userChrome.css
│   │       └── userContent.css
│   ├── gnome-text-editor themes (Paste to root)
│   │   └── usr
│   │       └── share
│   │           └── gnome-text-editor
│   │               └── styles
│   │                   ├── catppuccin-frappe.xml
│   │                   ├── catppuccin-latte.xml
│   │                   ├── catppuccin-macchiato.xml
│   │                   ├── catppuccin-mocha.xml
│   │                   ├── everforest-b.xml
│   │                   ├── tokyo_night_dark.xml
│   │                   └── tokyo_night_storm.xml
│   ├── tabliss (firefox start page extension)
│   │   └── tabliss.json
│   └── vscode theme
│       └── gruvbox-dark-hard_BUT_RED.json
├── LICENSE
├── .local
│   └── bin
│       ├── record-script-fullscreen.sh
│       ├── record-script.sh
│       ├── rubyshot
│       └── switchrice.sh
├── Projects
│   ├── notify-receive
│   │   ├── Cargo.lock
│   │   ├── Cargo.toml
│   │   └── src
│   │       ├── dbus.rs
│   │       └── main.rs
│   └── README.md
├── README.md
````
<div>i don't fix eww anymore, it still having bugs, don't and never use it, unless you want a lag bar and will harm itself</div>
