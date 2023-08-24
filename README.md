# shibafes2023-visitors-counter

来場者カウント＆7セグ表示システム  

**TOC**  

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [shibafes2023-visitors-counter](#shibafes2023-visitors-counter)
  - [開発環境構築(Linux)](#開発環境構築linux)
    - [Raspberry Pi Pico用](#raspberry-pi-pico用)
      - [1. RaspberryPiSDKのリポジトリクローン](#1-raspberrypisdkのリポジトリクローン)
      - [2. 以下をインストール](#2-以下をインストール)
      - [3. `PICO_SDK_PATH`を設定](#3-pico_sdk_pathを設定)
      - [4. コンパイルし、UF2ファイルを作成](#4-コンパイルし-uf2ファイルを作成)
      - [5. 生成されたUF2ファイルを、RaspberryPiPicoにコピー](#5-生成されたuf2ファイルを-raspberrypipicoにコピー)
        - [マウントされていなかった場合の対処](#マウントされていなかった場合の対処)
        - [マウント後](#マウント後)
      - [(おまけ)デバッグなどでUSBシリアルを利用する場合](#おまけデバッグなどでusbシリアルを利用する場合)

<!-- /code_chunk_output -->

## 開発環境構築(Linux)

### Raspberry Pi Pico

ほぼ自分用メモ。RaspberryPiPicoにどうやって書き込むねんってなったときに参考にしてください。  
詳細は[RaspberryPi公式ドキュメント](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)のChapter2参照。

#### 1. RaspberryPiSDKのリポジトリクローン

homeディレクトリ下にpicoディレクトリを設定後、RaspberryPiSDKのリポジトリをクローンします。

```bash
cd ~/
mkdir pico
cd pico
git clone https://github.com/raspberrypi/pico-sdk.git --branch master
cd pico-sdk
git submodule update --init
cd ..
git clone https://github.com/raspberrypi/pico-examples.git --branch master
cd pico-sdk
git pull
git submodule update
```

#### 2. 以下をインストール

aptやdnfでインストールします。

- cmake
- gcc-arm-none-eabi
- libnewlib-arm-none-eabi
- build-essential

#### 3. `PICO_SDK_PATH`を設定

注）1. でSDKのリポジトリを別の箇所にクローンした場合は、そのパスを通す。  

```bash
export PICO_SDK_PATH=~/pico/pico-sdk
```

#### 4. コンパイルし、UF2ファイルを作成

クローンしていない場合はこのrepoをクローン

```bash
cd 任意のパス
git clone https://github.com/TsukasaTakahashi-z8/shibafes2023-visitors-counter.git --branch main
cd shibafes2023-visitors-counter
```

cmakeでコンパイル

```bash
cd このリポジトリのパス/pico
// e.g. ~/shibafes2023-visitors-counter/pico

mkdir build  //ビルド用ディレクトリ
cd build
cmake ..
make -j4
ls | grep *.uf2  //uf2ファイルの存在確認
```

#### 5. 生成されたUF2ファイルを、RaspberryPiPicoにコピー

BOOTSELを押しながら、RaspberryPiPicoをこのPCにUSB接続し、マウントする。デスクトップ版は、自動でマウントされるらしい。  
RPi-RP2が認識されるので、そこに先程の`(ファイル名).uf2`をコピーする。`cp`コマンドでなくとも可。  
ここでは、`seven-segment-display.uf2`。  

##### マウントされていなかった場合の対処

ひとまず、Picoをマウントします。

```bash
$ fdisk -l | grep RP2 -B 1  //Picoがどのディスクか調べる
ディスク /dev/sd？: 128 MiB, 134217728 バイト, 262144 セクタ
Disk model: RP2 
```

これで、`/dev/sd?`がRaspberryPiPicoであることがわかります。(`/dev/sd?`は、/dev/sdfなどです。)  
sudoでマウントします。ここで、数字が入ったものを使うことに注意してください。

```bash
sudo mkdir -p /media/cesium133/RPI-RP2
sudo mount /dev/sd？1 /media/cesium133/RPI-RP2
```

##### マウント後


作ったUF2ファイルをコピーします。

```bash
sudo cp ./seven-segment-display.uf2 /media/cesium133/RPI-RP2/seven-segment-display.uf2
```

すると、Picoが自動で再起動して書き込んだプログラムが実行される。

#### (おまけ)デバッグなどでUSBシリアルを利用する場合

CMakeLists.txtに以下を追加

```CMake
target_link_libraries(seven-segment-display pico_stdlib hardware_uart) # 引数にhardware_uartを追加した。

pico_enable_stdio_usb(seven-segment-display 1)
pico_enable_stdio_uart(seven-segment-display 0)
```

コンパイル&インストールし直す。
その後、minicomなどで接続。

```bash
sudo minicom -b 115200 -o -D /dev/ttyACM0
```

