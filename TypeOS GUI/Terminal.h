#ifndef _TERMINAL_H_
#define _TERMINAL_H_
#include "vga.h"
#include "keyboard.h"

int offsetY = 10;

extern void Crash();

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

void _App_TEST()
{
    int i, j;
    int first = 1l;
    char c;
    for(i = 0;;i++)
    {
        for(j = 0;j<200;j++)
        {
            SetPixel(i%320,j%200,i%256);
            if (first == 1)
            {
                for(;first != 0;)
                {
                    c = getch();
                    if(!c) first = 0;
                }
            }
        }
        c = getch();
        if(c == 0x1B) {ClearScreen(0x00);offsetY=-8;return;}
    }
}

void _App_CODE()
{
    int i, j;
    int first = 1;
    char c;
    if (first == 1)
    {
        for(;first != 0;)
        {
            c = getch();
            if(!c) first = 0;
        }
    }
    ClearScreen(0x20);
    print("THIS FEATURE REQUIRES A NEWER VERSION OF TYPEOS", 1, 1, 0x0F);
    for(;;)
    {
        c = getch();
        if(c == 0x1B) {ClearScreen(0x00);offsetY=-8;return;}
    }
}

void Process(char command[4])
{
    if(*(long*)command == *(long*)"KLAR") {ClearScreen(0x00); offsetY = -8; return;}
    if(*(long*)command == *(long*)"HALT") {Crash(); return;}
    if(*(long*)command == *(long*)"TYPE") {_App_TYPE(); return;}
    if(*(long*)command == *(long*)"TEST") {_App_TEST(); return;}
    if(*(long*)command == *(long*)"CODE") {_App_CODE(); return;}
}

extern void Crash()
{
    ClearScreen(0x04);
    print("SYSTEM HAS CRASHED", 1, 1, 0x00);
    for(;;);
}

#endif