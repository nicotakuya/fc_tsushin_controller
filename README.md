# 通信コントローラ(HVC-051)の動作テスト for FC
## 概要
ファミコンの周辺機器、「通信コントローラ(HVC-051)」の動作テストをするプログラムです。

## Files
build.bat：ビルドするバッチファイルです。開発環境は「cc65」を使っています。

rom.nes：ROMイメージファイル。

## 使い方
対応カートリッジはMapper 0。PRG-ROM 32KB(FLASH)、CHR-RAM 8KB(SRAM)。
https://github.com/nicotakuya/diyfccartridge

rom.nesをカートリッジに書き込んでファミコンで動かします。

ファミコンの拡張端子(EXPAND CONNECTOR)に通信コントローラを接続します。

起動後、通信コントローラのボタンを押すと、画面の該当箇所に「＞」のマークが表示されます。

## Screenshot
<img width="514" height="452" alt="Image" src="https://github.com/user-attachments/assets/5706e38e-05d5-498b-b792-cf0a18aaceb9" />

## 通信コントローラのタイミングチャート
<img width="1240" height="371" alt="Image" src="https://github.com/user-attachments/assets/3abbcab0-b9a4-4292-9d40-d324a7439969" />

## 参考資料
NesDev Wiki

https://www.nesdev.org/wiki/Famicom_Network_Controller
