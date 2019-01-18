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
