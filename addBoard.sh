#!/bin/bash

# Version 1
# Run this script to add the Cloudboard32 to your PlatformIO instance.
#

bail=false
echo -e "\nValidating VSCode and PlatformIO installation."

if [[ -d ~/.platformio ]]
then
    echo "~/.platformio" 
else
    echo "Error: ~/.platformu does not exist."
    bail=true
fi

if [[ -d ~/.platformio/packages ]]
then
    echo "~/.platformio/packages" 
else
    echo "Error: ~/.platformio/packages does not exist."
    bail=true
fi

if [[ -d ~/.platformio/platforms ]]
then
    echo "~/.platformio/platforms" 
else
    echo "Error: ~/.platformio/platforms does not exist."
    bail=true
fi

if [ $bail == true ]
then
    echo -e "\nFIX: Resinstall PlatformIO from within VSCode.\n"
    exit 0
fi

echo -e "\nAdding Cloudboard definition..."
cp -rf platformio/packages/framework-arduinoespressif32/variants/Cloudboard-32 ~/.platformio/packages/framework-arduinoespressif32/variants
echo -e "Added pins."

cp -f platformio/platforms/espressif32/boards/cloudboard-32.json ~/.platformio/platforms/espressif32/boards
echo -e "Added board."

cp -rf platformio/platforms/espressif32/examples/* ~/.platformio/platforms/espressif32/examples
echo -e "Added examples."

echo -e "\nDone... Happy Coding.\n"