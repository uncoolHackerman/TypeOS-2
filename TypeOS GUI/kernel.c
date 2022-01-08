#include "Terminal.h"
#define KB_SIZE 4

extern void main()
{
    int blink = 0;
    char KBbuff[KB_SIZE];
    int NewCMD = 1;
    initKB();
    initFont();
    print("TYPEOS GRAPHICS EDITION", 1, 0, 0x0F);
    char c;
    int i, j;
    int offset = 1;
    int first = 1;
    while(1)
    {
        if(NewCMD)
        {
            offsetY += 9;
            PrintC('@', 1, offsetY, 0x0F);
            offset += 5;
            NewCMD = 0;
        }
        for(i = 0; i < KB_SIZE;)
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
                PrintC('~', offset, offsetY, 0);
                PrintC(c, offset, offsetY, 0x0F);
                KBbuff[i] = c;
                first = 1;
                offset += 5;
                i++;
            }
            PrintC('_', offset, offsetY, 0x0F);
        }
        PrintC('~', offset, offsetY, 0);    // remove cursor before executing commands
        offsetY += 9;
        offset = 1;
        Process(KBbuff);
        NewCMD = 1;
        for(j = 0; j < KB_SIZE; j++)
        {
            KBbuff[j] = 0;
        }
        if(offsetY > 180) {ClearScreen(0x00); offsetY = 1;}
    }
    return;
}