# Essentials
## Navigation
### cd and ls
#### Definition:
cd is to change the directory you're currently in, ls is to peek into your current directory, or wherever you want if you put in a directory
#### Uses:
Pretty self explanatory for looking through your files and will be essential always
#### Terminal:
```
cd directory/directory/.../
```
Leave no directory to check current directory
```
ls directory/directory/.../
```
#### Notes:
Starting directories with / will send you to root 
```
cd /
```
Starting directories with ~/ will send you to home,
```
cd ~/
```
## Package updating

## Battery Conservation
### TLP
Because Linux is so power intensive compared to windows, TLP helps conserve battery life automatically so you don't have to dig into processes
#### Documentation - <https://linrunner.de/tlp/usage/tlp.html>
Set to start on boot, but if installed this can be run to avoid reboot
```
tlp start
```
Check
```
tlp-stat - s
```
Switch between Plugged and Battery mode
```
tlp bat | ac
```
Enable/disable bluetooth/nfc/wifi/wwan (choose on, off, or toggle)
```
<name> on | off | toggle
```
#### Notes
90% of the commands that require tlp in the beginning will need root permissions so write sudo before each command
# Quality of Life
### Symlinks
#### Definition:
A symlink is like a pointer that points to a file/folder, and can be accessed as if the symlink were the actual file/folder, contents included if it were a folder
#### Uses:
I find it helpful when running a dual booted system and I want to access files from the windows side without having to dig into my /mnt/... directories
#### Terminal:
	ln -s <directory you want to symlink>/ <directory to put symlink>/