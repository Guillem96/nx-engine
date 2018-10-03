#!/bin/bash

# Installing devkitpro
sudo pacman -S $(pacman -Ssq switch-*) 
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPPC=/opt/devkitpro/devkitPPC