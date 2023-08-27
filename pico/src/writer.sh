#!/usr/bin/bash
if [ -z "$1" ] || [ -z "$2" ]
then
    echo "引数が指定されていません。"
    exit 0
else
    RPI=`readlink -f /dev/disk/by-label/RPI-RP2`
    echo $1
    echo $2
    echo $RPI
    export PICO_SDK_PATH="$1"

    if [ -d ./build ]
    then
        echo "remove build dir"
        sudo rm -rf ./build
    fi

    if [ -d /media/$USER/RPI-RP2 ]
    then
        echo "RPI-RP2 is already mounted"
    else
        echo "mount $RPI /media/$USER/RPI-RP2"
        sudo mkdir -p /media/$USER/RPI-RP2
        sudo mount $RPI /media/$USER/RPI-RP2
    fi

    mkdir ./build
    cd ./build
    cmake ..
    make -j4
    cd ..
    sudo cp ./build/$2/$2.uf2 /media/$USER/RPI-RP2/
    echo "copied."
    sudo umount /media/$USER/RPI-RP2
    echo "unmounted"
    sudo rm -rf /media/$USER/RPI-RP2
    echo "completed"
fi
exit 0
