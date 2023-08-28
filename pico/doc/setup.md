# Raspberry Pi Picoのための環境構築

ほぼ自分用メモ。RaspberryPiPicoにどうやって書き込むねんってなったときに参考にしてください。  
現在このリポジトリ内ではC言語はあつかっていないので需要はないと思いますが、一応C/C++での書き込み方法も書きました。  
[C/C++をRaspberry Piに書き込む方法](./setup-c.md)

## とりあえずこのrepoをクローン

```bash
cd 任意のパス
git clone https://github.com/TsukasaTakahashi-z8/shibafes2023-visitors-counter.git --branch main
cd shibafes2023-visitors-counter
```

## Raspberry Pi Picoのマウント方法

ひとまず、Picoをマウントします。
Picoがどれかを調べます。

```bash
readlink -f /dev/disk/by-label/RPI-RP2
```

これで、`/dev/sd?`がRaspberryPiPicoであることがわかります。(`/dev/sd?`は、/dev/sdf1などです。)  
sudoでマウントします。ここで、数字が入ったものを使うことに注意してください。

```bash
sudo mkdir -p /media/$USER/RPI-RP2
sudo mount /dev/sd？1 /media/$USER/RPI-RP2
```
