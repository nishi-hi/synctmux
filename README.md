# synctmux
## Introduction
Synchronize tmux. This is a software for executing the same command on local host or remote host by using tmux sessions.

## Prerequisite
- tmux >= 3.0
- xclip (Linux)
- pbcopy (macOS)

## Getting started
```
wget https://github.com/nishi-hi/synctmux/releases/latest/synctmux-<version>.tar.gz
or
curl -O https://github.com/nishi-hi/synctmux/releases/latest/synctmux-<version>.tar.gz
tar xzf synctmux-<version>.tar.gz --no-same-permission
cd synctmux-<version>
./configure --prefix=<path_to_install>
make
make install
<path_to_install>/bin/synctmux --help
```
