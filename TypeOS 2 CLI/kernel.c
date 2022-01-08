#include "Terminal.h"
#define KBsize 4

extern void main()
{
    char KBbuff[KBsize];
    Console.x = 0;
    Console.y = 0;
    Console.colour = 0x0F;
    print("TypeOS 2 i386 Mode\n");
    char c;
    int first = 1;
    int second = 0;
    int i;
    int j;
    wait:
    while(first == 1)
    {
        c = getch();
        if(c == 0) first = 0;
    }
    if(second == 1) goto exit1;
    while(1)
    {
        exit:
        printC('\n');
        printC('$');
        for(i = 0; i < KBsize;)
        {
            exit1:
            c = getch();
            if(c)
            {
                if(c == '\n') {Process(KBbuff); goto exit;}
                printC(c);
                KBbuff[i] = c;
                i++;
                first = 1;
                second = 1;
                goto wait;
            }
        }
        Process(KBbuff);
        for(j = 0; j < KBsize; j++)
        {
            KBbuff[j] = 0;
        }
        if(Console.y > 20) clear();
    }
    return;
}