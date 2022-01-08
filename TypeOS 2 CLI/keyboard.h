#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

char UKlayout[255] = {0, 0x1B, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0x08, 
                      0, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 
                      0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '@', 0xA9, 0, '~', 
                      'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '?', 0, 
                      '*', 0xB1, ' ', 0xB2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

extern void GetKB(void);

char getch(void)
{
    GetKB();
    if(*(char*)0xFFF) return UKlayout[*(char*)0xFFF];
}

#endif