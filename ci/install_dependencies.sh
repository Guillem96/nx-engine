#!/usr/bin/env sh

# Intalling pacman
wget -O "pacman.deb" https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb
sudo dpkg  -i pacman.deb
rm pacman.deb

# Installing devkitpro
sudo pacman -S $(pacman -Ssq switch-*) 
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPPC=/opt/devkitpro/devkitPPC