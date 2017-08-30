#!/bin/bash


# Install X11 XShm extension

sudo apt-get install --assume-yes libxext-dev 2>/dev/null

# Setup your OS

echo "Cloning minilibx library ..."
cd /tmp
git clone https://github.com/abouvier/minilibx 2>/dev/null
echo "Cloning minilibx library ... OK"
echo "Installing mlx ..."
mkdir /usr/X11 2>/dev/null
mkdir /usr/X11/include 2>/dev/null
mkdir /usr/X11/lib 2>/dev/null
mkdir /usr/local/lib 2>/dev/null
cd minilibx 2>/dev/null
make 2>/dev/null
cp mlx.h /usr/X11/include 2>/dev/null
cp mlx.h /usr/local/include 2>/dev/null
cp libmlx.a /usr/X11/lib 2>/dev/null
cp libmlx.a /usr/local/lib 2>/dev/null
echo "Installing mlx ... OK"
echo "Do not forget to insert good flags in your Makefile : \n"
echo "FLAGS = -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11"