#!/bin/bash
rm -rf /tmp/.X1*
mkdir ~/.vnc
x11vnc -storepasswd 1234 ~/.vnc/passwd
Xvfb :1 -screen 0 800x600x16 &
x11vnc -display :1.0 -usepw &
echo "export DISPLAY=:1.0" >> ~/.bashrc
/usr/share/novnc/utils/launch.sh --vnc localhost:5900 &
bash