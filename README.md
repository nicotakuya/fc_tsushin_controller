# 通信コントローラ(HVC-051)の動作テスト
## 概要
ファミコンの周辺機器、「通信コントローラ(HVC-051)」の動作テストをするためのプログラムです。
## ビルド方法
開発環境はcc65 C compilerを使っています。推奨するOSはWindowsです。
build.batを実行すると、ROMイメージファイルの「rom.nes」が作成されます。

## 使い方
rom.nesをファミコンのカートリッジに書き込みます。プログラムROMは32KB。キャラクターRAMは8KB(SRAM)です。
ファミコンにカートリッジと通信コントローラを接続して起動します。
通信コントローラのボタンを押すと、画面の該当箇所に「＞」のマークが表示されます。

## Screenshot
<img width="514" height="452" alt="Image" src="https://github.com/user-attachments/assets/5706e38e-05d5-498b-b792-cf0a18aaceb9" />

## 通信コントローラのタイミングチャート
<img width="1240" height="371" alt="Image" src="https://github.com/user-attachments/assets/3abbcab0-b9a4-4292-9d40-d324a7439969" />

## 参考資料
Nesdev Wiki

https://www.nesdev.org/wiki/Famicom_Network_Controller
