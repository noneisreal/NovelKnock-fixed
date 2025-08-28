## Contributing
- I can accept changes from you, if not surely it will work, please make a fork to changes or you can make a issue, the good way is ask me though the issue on github
## Setting
- You need an Arch(-based) system
- And run this to install all things necessary for working
```
yay -S stb nlohmann-json wal python-pywal clangd backlight jq gojq python-pillow cargo gcc python-material-color-utilities-git cava quickshell-git eww gtklock rofi
```
- Then copy all files in `NovelKnock-dots-hyprland-fixed/.config` to your `$HOME/.config` folder, do it with `./local` files, all this changes need to do when not already login into hyprland
- If still unsure about this, using another account (not necessary but recommend)

## Running
- Logout your session and login into hyprland

## note:
- Recommmend play music by app outside
- If still want play on browser, recommmend zen-browser, firefox, or firefox-based
- not recommmend chrome without extension Plasma Integation unless you want the eww show the thumbnail and artist etc
- I haven't fixed files in `.local` files yet, so function about lock screen will soon in next time
- and if eww sometimes lag, please using shotcuts `ctrl + alt + F2/F3` and then login into you account and `pkill eww`
- If just sth like not accept thumbnail from music player, use the bottom `reload hyprland config and eww` in side left
- If eww still doesn't accept, reload your tab play music, or with music player outside, it seems it has problem, open an issue and report that to me (with logs too)
- Temporary using rofi, if using launcher from eww, don't ask me why it don't accept the icons
