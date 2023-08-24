#!/usr/bin/bash
if [ -z "$1" ] && [ -z "$2" ]
then
    echo "引数が指定されていません。"
    fdisk -l | grep RP2 -B 1
    exit 0
else
    echo $1
    echo $2
    export PICO_SDK_PATH="$2"

    if [ -d ./build ]
    then
        echo "remove build dir"
        sudo rm -rf ./build
    fi

    if [ -d /media/$USER/RPI-RP2 ]
    then
        echo "RPI-RP2 is already mounted"
    else
        echo "mount /dev/$1 $USER /media/$USER/RPI-RP2"
        sudo mkdir -p /media/$USER/RPI-RP2
        sudo mount /dev/$11 /media/$USER/RPI-RP2
    fi

    mkdir ./build
    cd ./build
    cmake ..
    make -j4
    cd ..
    sudo cp ./build/seven-segment-display.uf2 /media/$USER/RPI-RP2/seven-segment-display.uf2
    echo "copied."
    sudo umount /media/$USER/RPI-RP2
    echo "unmounted"
    sudo rm -rf /media/$USER/RPI-RP2
    echo "completed"
fi
exit 0
