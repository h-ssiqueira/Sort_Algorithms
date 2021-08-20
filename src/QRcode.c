#include <stdio.h>
#define black_and_white "\033[30;47m"
#define reset "\033[0m"

void endl(){
    printf(reset);
    printf("\n");
}

void empty_line(){
    printf(black_and_white);
    for(int i = 0; i < 70; i++)
        printf(" ");
    endl();
}

// https://github.com/h-ssiqueira
void QR_code(){ // 35x70
    endl();
    empty_line(); // 1
    printf(black_and_white"  ██████████████        ████          ██████  ██  ██  ██████████████  "); // 2
    endl();
    printf(black_and_white"  ██          ██  ████    ██        ████    ████      ██          ██  "); // 3
    endl();
    printf(black_and_white"  ██  ██████  ██  ████  ██  ██  ██████████  ████  ██  ██  ██████  ██  "); // 4
    endl();
    printf(black_and_white"  ██  ██████  ██  ██          ██    ████    ████████  ██  ██████  ██  "); // 5
    endl();
    printf(black_and_white"  ██  ██████  ██  ████    ████  ██  ████████  ██████  ██  ██████  ██  "); // 6
    endl();
    printf(black_and_white"  ██          ██  ██████    ████      ██          ██  ██          ██  "); // 7
    endl();
    printf(black_and_white"  ██████████████  ██  ██  ██  ██  ██  ██  ██  ██  ██  ██████████████  "); // 8
    endl();
    printf(black_and_white"                    ██    ████████████        ██                      "); // 9
    endl();
    printf(black_and_white"      ██    ████████████  ██  ████  ██  ██      ██████  ██████████    "); // 10
    endl();
    printf(black_and_white"  ████    ████      ██    ██        ██████  ██████████████  ████  ██  "); // 11
    endl();
    printf(black_and_white"      ██  ██  ██            ████  ██████        ██  ██  ████  ██  ██  "); // 12
    endl();
    printf(black_and_white"    ██    ████    ██                            ██      ██      ████  "); // 13
    endl();
    printf(black_and_white"  ██      ██  ████████    ██  ██                ████  ████  ██    ██  "); // 14
    endl();
    printf(black_and_white"      ██        ██████    ██████                ██  ██████  ██    ██  "); // 15
    endl();
    printf(black_and_white"    ██    ██  ██████████  ██  ██                ████    ██    ██  ██  "); // 16
    endl();
    printf(black_and_white"          ████  ██  ████          ████        ████  ██      ██    ██  "); // 17
    endl();
    printf(black_and_white"      ██      ██████            ██            ████    ████  ██        "); // 18
    endl();
    printf(black_and_white"  ██████              ██          ██    ████    ██  ████      ██  ██  "); // 19
    endl();
    printf(black_and_white"  ████    ████████████        ████    ██      ████  ████████████  ██  "); // 20
    endl();
    printf(black_and_white"  ██    ████    ████                    ██    ████  ██    ████  ██    "); // 21
    endl();
    printf(black_and_white"  ██  ██    ████  ██  ██            ████        ██████████        ██  "); // 22
    endl();
    printf(black_and_white"      ██████      ████                            ██    ██    ██  ██  "); // 23
    endl();
    printf(black_and_white"  ████        ██████  ██  ████    ██████    ████  ██████████  ██  ██  "); // 24
    endl();
    printf(black_and_white"      ██          ████  ██      ██  ████████  ██████    ██  ██  ████  "); // 25
    endl();
    printf(black_and_white"  ██████  ██  ██      ████████  ████  ██████      ██████████          "); // 26
    endl();
    printf(black_and_white"                  ██  ██  ████    ██          ██████      ██████  ██  "); // 27
    endl();
    printf(black_and_white"  ██████████████  ██  ██        ████        ████  ██  ██  ██      ██  "); // 28
    endl();
    printf(black_and_white"  ██          ██  ██  ██    ██    ██████      ██████      ████  ████  "); // 29
    endl();
    printf(black_and_white"  ██  ██████  ██              ████      ██████████████████████        "); // 30
    endl();
    printf(black_and_white"  ██  ██████  ██        ██  ████  ████████  ██████████  ████  ████    "); // 31
    endl();
    printf(black_and_white"  ██  ██████  ██  ██    ██      ██      ██  ████████      ██  ██████  "); // 32
    endl();
    printf(black_and_white"  ██          ██    ████  ██        ████████      ████      ██        "); // 33
    endl();
    printf(black_and_white"  ██████████████      ██  ██  ████      ████████  ██  ██  ██      ██  "); // 34
    endl();
    empty_line(); // 35
    endl();
}
/*
int main(){
    qr_code1();
    return 0;
}*/