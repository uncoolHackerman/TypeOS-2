#ifndef _TERMINAL_H_
#define _TERMINAL_H_
#include "keyboard.h"

void _App_TYPE();

typedef struct
{
    unsigned long x;
    unsigned long y;
    unsigned char colour;
} ScreenData;

ScreenData Console;

void moveCursor(ScreenData destination)
{
    if(destination.x > 80) { destination.x %= 80; destination.y += destination.x / 80 + 1;}
    if(destination.y > 25) destination.y %= 25;
    Console.x = destination.x;
    Console.y = destination.y;
    return;
}

void printC(char c)
{
    unsigned long loc;
    ScreenData MovCur;
    MovCur.x = Console.x;
    MovCur.y = Console.y;
    loc = 0xb8000 + ((Console.y * 80 + Console.x) * 2);
    if(c == 0x0A)
    {
        MovCur.x = 0;
        MovCur.y++;
        goto update;
    }
    else *(char*)loc = c;
    loc++;
    *(char*)loc = Console.colour;
    MovCur.x++;
    update:
    moveCursor(MovCur);
    return;
}


void print(const char* str)
{
    while(*str != 0)
    {
        printC(*str);
        str++;
    }
    return;
}

void clear()
{
    int i;
    int loc;
    for(i = 0; i <= 4000; i++)
    {
        loc = 0xb8000 + (i * 2);
        *(char*)loc = 0;
        loc++;
        *(char*)loc = Console.colour;
    }
    Console.x = 0;
    Console.y = 0;
    return;
}


extern void Crash()
{
    Console.colour = 0x40;
    clear();
    print("The System caught a fatal error and stopped");
    while(1);
}

void Process(char command[4])
{
    if(command[0] == 'K' && command[1] == 'L'
       && command[2] == 'A' && command[3] == 'R') {clear(); return;}
    if(command[0] == 'H' && command[1] == 'A'
       && command[2] == 'L' && command[3] == 'T') {Crash(); return;}
    if(command[0] == 'T' && command[1] == 'Y'
       && command[2] == 'P' && command[3] == 'E') {_App_TYPE(); return;}
    else
    {
        print("\n");
        print(command);
        print(" was not a valid command");
    }
    return;
}

void _App_TYPE()
{
    print("\n");
    char c;
    int first = 1;
    int second = 0;
    wait:
    while(first == 1)
    {
        c = getch();
        if(c == 0) first = 0;
    }
    if(second == 1) goto exit1;
    while(1)
    {
        exit1:
            c = getch();
            if(c)
            {
                if(c == 0x1B) return;
                printC(c);
                first = 1;
                second = 1;
                goto wait;
            }
    }
    return;
}


#endif