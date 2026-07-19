# 通信コントローラ(HVC-051)の動作テスト
## 概要
ファミコンの周辺機器、「通信コントローラ(HVC-051)」の動作テストをするためのプログラムです。

## 使い方
rom.nesをファミコンのカートリッジに書き込みます。プログラムROMは32KB。キャラクターRAMは8KB(SRAM)です。
ファミコンにカートリッジと通信コントローラを接続して起動します。
通信コントローラのボタンを押すと、画面の該当箇所に「＞」のマークが表示されます。

## Screenshot
<img width="514" height="452" alt="Image" src="https://github.com/user-attachments/assets/5706e38e-05d5-498b-b792-cf0a18aaceb9" />

## 参考資料
Nesdev Wiki
https://www.nesdev.org/wiki/Famicom_Network_Controller
