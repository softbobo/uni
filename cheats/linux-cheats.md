# Linux Cheat Sheet

Listing of useful commands mainly for the POSIX-compliant software on Linux Systems.
No guarantee for factual correctness is given.

## dd
dd is capable of copying and converting files according to specified operands. to use it to create a live usb distro from an .iso type:
```sudo dd bs=4M if=/path/to/iso/file of=path/to/usb/key status=progress```
## fdisk
List all partitions (including mounted): `sudo fdisk -l` 
## pacman
__Remove__ a package with depencies (if those are not used by other packages): 
```pacman -Rs [package_name]```
## OpenSSH
Log into remote: ```ssh {user}@{server}```  
Log out normally: Close the shell with `exit`  
Force-log out: `Enter` and then `~.` 
## scp - Secure Copy
scp is used to move files back and forth between local and remote machines. to copy a file from local to remote use
`scp /path/to/source user@remote:/path/to/remote/folder`
## tar
to untar a tar.gz (tarred and gzipped) file, four command-line options are recommended:
`x` extract
`v` for verbose
`z` unzip via gzip
`f` last flag, always. sets filename and location
according syntax is `tar -xvzf [filename].tar.gz`
to unmount to a different location then current working directory, use the -C flag like so: `tar xvzf [filename].tar.gz -C path/to/directory`
## umount
Unmount partition (also external): `sudo umount path/to/drive`
## xfce4
If xfce is your DE, you can use this command to set up a new tab in the current terminal window and execute a program:
```xfce4-terminal --tab --title='venv' -x bash -c "cd path/do/folder; source venv/bin/activate"``` 
refer to this: https://superuser.com/questions/471517/how-can-i-save-my-multiple-tabs-session-in-an-xfce4-terminal?newreg=c778a6a5563e4b4083b21bdbf74b301f