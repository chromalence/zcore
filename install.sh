#!/usr/bin/env bash 

LIB_PATH="/usr/local/include"
BIN_PATH="/usr/local/bin"
TIMER=5

echo "installing zcore.."
sudo mkdir -p "$LIB_PATH/zcore" &&
sudo cp -r lib/* "$LIB_PATH/zcore/" && 
echo "zcore finished installing into $LIB_PATH/zcore"
echo "tbt installing in $TIMER/s ( <CTRL+C> to abort nothing will break )"
sleep(5) &&
sudo mkdir -p "$BIN_PATH"
sudo cp -r extras/* "$BIN_PATH" &&
echo "tbt finished installing"
echo "good luck! thank you for installing!!!"
echo "- chro"

