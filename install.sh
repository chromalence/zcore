#!/usr/bin/env bash 

LIB_PATH="/usr/local/include"
BIN_PATH="/usr/local/bin"
MAN_PATH="/usr/local/man/man7"
TIMER=5

# do the dependency check yourself its safer anyway hope you understand

echo "installing zcore.."
sudo mkdir -p "$LIB_PATH/zcore" &&
sudo cp -r lib/* "$LIB_PATH/zcore/" && 
echo "installing zcore man 7.." &&
sudo cp doc/zcore.7 "$MAN_PATH/zcore.7" &&
echo "zcore finished installing into $LIB_PATH/zcore"
echo "tbt installing in $TIMER/s ( <CTRL+C> to abort nothing will break )"
echo "make sure you have: elfkickers / elf-kickers & a C compiler"
sleep 5 &&
sudo mkdir -p "$BIN_PATH" &&
sudo cp -r extra/tbt "$BIN_PATH" &&
echo "tbt finished installing" &&
echo "good luck! thank you for trying!!!"
echo "- chro"

