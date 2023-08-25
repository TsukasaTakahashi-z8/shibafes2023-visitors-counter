# shibafes2023-visitors-counter

来場者カウント＆7セグ表示システム  


## TOC

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [shibafes2023-visitors-counter](#shibafes2023-visitors-counter)
  - [TOC](#toc)
  - [Features](#features)
  - [環境構築](#環境構築)

<!-- /code_chunk_output -->

## Features

必要なデバイス

- Raspberry Pi 3A+
  - ローカルWEBサーバ兼、7セグ制御
  - UARTでRaspberry Pi Picoに接続

- Raspberry Pi Pico
  - 7セグ制御
  - UARTでRaspberry Pi 3A+に接続

- ブラウザ搭載の、ネットワーク接続可能なデバイス(e.g. スマホ)
  - ブラウザでRaspberry Pi 3A+のサーバにアクセス
  - 来場者がブラウザ内のボタンをタッチで、カウントされる

- 表示用7セグ

## 環境構築

ここでは、Raspberry Pi 3A+への説明をします。
Raspberry Pi Picoは、[./pico/doc/setup.md](pico/doc/setup.md)を参照してください。
