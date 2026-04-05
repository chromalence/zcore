#!/usr/bin/env bash 

LIB_PATH="/usr/local/include"
BIN_PATH="/usr/local/bin"
MAN_PATH="/usr/local/man/man7"
TIMER=5


check_deps() { # its big but expandable
  local missing=()
  for tool in elfkickers gcc sstrip; do # linux comes with gcc so it shouldnt be an issue
    if ! command -v "$tool" &> /dev/null; then
      missing+=("$tool")
    fi
  done

  if [ ${#missing[@]} -ne 0 ]; then
    echo "-- missing dependencies: ${missing[*]} --"
    
    if command -v pacman &> /dev/null; then
      sudo pacman -S "${missing[@]}"
    elif command -v apt &> /dev/null; then
      sudo apt install "${missing[@]/nvim/neovim}" 
    elif command -v dnf &> /dev/null; then
      sudo dnf install "${missing[@]}"
    elif command -v xbps-install &> /dev/null; then
      sudo xbps-install "${missing[@]}"
    elif command -v zypper &> /dev/null; then
      sudo zypper install "${missing[@]}"
    elif command -v emerge &> /dev/null; then
      sudo emerge "${missing[@]}"
    fi
    
  else
    echo "all dependencies found congrats"
  fi
}

echo "installing zcore.."
sudo mkdir -p "$LIB_PATH/zcore" &&
sudo cp -r lib/* "$LIB_PATH/zcore/" && 
echo "installing zcore man 7.." &&
sudo cp doc/zcore.7 "$MAN_PATH/zcore.7" &&
echo "zcore finished installing into $LIB_PATH/zcore"
echo "tbt installing in $TIMER/s ( <CTRL+C> to abort nothing will break )"
sleep 5 &&
check_deps &&
sudo mkdir -p "$BIN_PATH" &&
sudo cp -r extra/tbt "$BIN_PATH" &&
echo "tbt finished installing" &&
echo "good luck! thank you for trying!!!"
echo "- chro"

