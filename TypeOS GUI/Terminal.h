#ifndef _TERMINAL_H_
#define _TERMINAL_H_
#include "vga.h"

typedef struct
{
    char ukLayout[256];
} KBdef;

KBdef ConsoleKB;
int offsetY = 10;

extern void Crash();
extern void GetKB();

void initKB(void)
{
    int i;
    char kbUK[256] = {0, 0x1B, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0x08, 
                      0, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 
                      0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '@', 0xA9, 0, '~', 
                      'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '?', 0, 
                      '*', 0xB1, ' ', 0xB2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i = 0; i < 256; i++)
    {
        ConsoleKB.ukLayout[i] = kbUK[i];
    }
    return;
}

char getch(void)
{
    GetKB();
    char c = *(char*)0xFFF;
    return ConsoleKB.ukLayout[c];
}

void _App_TYPE()
{
    int first = 1;
    char c;
    int offset = 1;
    while(1)
    {
        if (first == 1)
        {
            for(;first != 0;)
            {
                c = getch();
                if(!c) first = 0;
            }
        }
        c = getch();
        if(c)
        {
            PrintC('~', offset, offsetY, 0x0F);
            if(c == 0x1B) return;
            PrintC(c, offset, offsetY, 0x0F);
            if(offset > 311) {offsetY += 9;offset = -4;}
            first = 1;
            offset += 5;
        }
        PrintC('_', offset, offsetY, 0x0F);
    }
}

void Process(char command[4])
{
    if(command[0] == 'K' && command[1] == 'L'
       && command[2] == 'A' && command[3] == 'R') {ClearScreen(0x00); offsetY = 1; return;}
    if(command[0] == 'H' && command[1] == 'A'
       && command[2] == 'L' && command[3] == 'T') {Crash(); return;}
    if(command[0] == 'T' && command[1] == 'Y'
       && command[2] == 'P' && command[3] == 'E') {_App_TYPE(); return;}
}

extern void Crash()
{
    ClearScreen(0x04);
    print("SYSTEM HAS CRASHED", 1, 1, 0x00);
    for(;;);
}

#endif