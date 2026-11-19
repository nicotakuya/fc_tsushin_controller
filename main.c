// 通信コントローラ(HVC-051)の動作テスト(main.c)
// by Takuya Matsubara
#include "fcsub.h"     // ファミコン用ライブラリ
#include "pattern.h"   // パターンテーブル用データ

void title(void);
void NesMain(void);

const char palette[] = { // カラーテーブル
    C_BLACK, C_GRAY   , C_GREEN     , C_WHITE ,   // BGパレット0
    C_BLACK, 0        , 0           , 0       ,   // BGパレット1
    C_BLACK, 0        , 0           , 0       ,   // BGパレット2
    C_BLACK, 0        , 0           , 0       ,   // BGパレット3
    C_BLACK, C_BLUE  , C_BLUE+0x10  , C_WHITE,    // SPパレット0
    C_BLACK, C_RED   , C_RED+0x10   , C_YELLOW ,  // SPパレット1
    C_BLACK, C_MAGENTA-0x10,C_MAGENTA,C_MAGENTA+0x10, // SPパレット2
    C_BLACK, C_GREEN-0x10 , C_GREEN , C_GREEN+0x10    // SPパレット3
};

const char strtitle[] = "TSUSHIN CONTROLLER(HVC-051)";
const char strcopyright[] = "(C)2026 Takuya Matsubara";

const char strbutton[24][7] = {
    "A     ",
    "B     ",
    "SELECT",
    "START ",
    "UP    ",
    "DOWN  ",
    "LEFT  ",
    "RIGHT ",
    "0     ",
    "1     ",
    "2     ",
    "3     ",
    "4     ",
    "5     ",
    "6     ",
    "7     ",
    "8     ",
    "9     ",
    "*     ",
    "#     ",
    ".     ",
    "C     ",
    "      ",
    "END   "
};


// タイトル
void title(void)
{
    char x,y,i;
    ppu_enable(0); // 表示を無効化
    bg_printstr(2,2,(char *)strtitle); // タイトル
    //bg_printstr(4,24,(char *)strcopyright); // 

    for(i=0; i<24; i++){
        x = (i % 3) * 8+3;
        y = (i / 3) * 2+5;
        bg_printstr(x,y,(char *)strbutton[i]);
    }
    ppu_enable(1); // 表示を有効化
    ppu_vsync();          // Vブランク待ち
}

unsigned long player1; // 
unsigned char player2; // 

#define JOY_D0 (1<<0)
#define JOY_D1 (1<<1)

//---- 通信コントローラ入力
void tsushin_ctr(void)
{
    char i;
    unsigned char tempdata;

    player1 = 0;
    JOYPAD1 = 0x01;    // load
    JOYPAD1 = 0x00;    // latch
    for(i=0; i<8; i++){
        player1 <<= 1;
        tempdata = JOYPAD1;
        if( tempdata & JOY_D0 ) player1 |= 1;  
        if( tempdata & JOY_D1 ) player1 |= 1;  
        player2 <<= 1;
        tempdata = JOYPAD2;
        if( tempdata & JOY_D0 ) player2 |= 1;  
    }

    for(i=0; i<16; i++){
        player1 <<= 1;
        tempdata = JOYPAD1;
        if( tempdata & JOY_D1 ) player1 |= 1;  
    }
}

// メイン関数
void NesMain(void)
{
    unsigned char i,x,y;
    unsigned char c;
    unsigned long mask;
    unsigned long player1_old;

    fc_init();      // 全機能の初期化
    // パターンテーブル設定
    ppu_pattern((unsigned char *)pattern,0,256);
    ppu_pattern8x16((unsigned char *)pattern+4096,256,256);

    ppu_palette((char *)palette,0,8);          // カラーパレット設定

    title();
    i=0;
    while (1){
        tsushin_ctr();  // 通信コントローラ入力

        if(i==0) mask = 0x800000;
        x = (i % 3) * 8+2;
        y = (i / 3) * 2+5;
        if(player1 & mask){
            c = '>';  // ボタンがON
        }else{
            c = ' ';  // ボタンがOFF
        }
        if(player1_old != player1){
            if(player1){  // OFF->ONに変化
                pulse1(300);
            }
        }
        player1_old = player1;
        mask >>= 1;
        i = (i+1) % 24;

        ppu_vsync();          // Vブランク待ち
        bg_printch(x,y,c);
        bg_scroll(0,0);
        sp_dmastart();        // OMA DMA転送開始
    }
}

