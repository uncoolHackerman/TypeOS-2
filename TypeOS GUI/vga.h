/*
    VGA video and Font Driver written by Gabriel Jickells
    08/01/2022 UK Date
*/

#ifndef _VGA_H_
#define _VGA_H_
#define VGA_MEMORY 0xA0000
#define SCREEN_SIZE 320 * 200

typedef struct
{
    int A[32];
    int B[32];
    int C[32];
    int D[32];
    int E[32];
    int F[32];
    int G[32];
    int H[32];
    int I[32];
    int J[32];
    int K[32];
    int L[32];
    int M[32];
    int N[32];
    int O[32];
    int P[32];
    int Q[32];
    int R[32];
    int S[32];
    int T[32];
    int U[32];
    int V[32];
    int W[32];
    int X[32];
    int Y[32];
    int Z[32];
    int at[32];
    int us[32];
} FONT;

FONT FontEnglish;

void initFont()
{
    int lA[32] = {0, 1, 1, 0,
                  1, 0, 0, 1, 
                  1, 0, 0, 1,
                  1, 1, 1, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1, 
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lB[32] = {1, 1, 1, 0, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 1, 1, 0, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 1, 1, 0};

    int lC[32] = {0, 1, 1, 1,
                  1, 0, 0, 0, 
                  1, 0, 0, 0, 
                  1, 0, 0, 0, 
                  1, 0, 0, 0, 
                  1, 0, 0, 0, 
                  1, 0, 0, 0, 
                  0, 1, 1, 1};

    int lD[32] = {1, 1, 1, 0,
                  1, 0, 0, 1, 
                  1, 0, 0, 1,
                  1, 0, 0, 1, 
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 1, 1, 0};

    int lE[32] = {1, 1, 1, 1, 
                  1, 0, 0, 0, 
                  1, 0, 0, 0,
                  1, 1, 1, 1,
                  1, 0, 0, 0,
                  1, 0, 0, 0, 
                  1, 0, 0, 0, 
                  1, 1, 1, 1, };

    int lF[32] = {1, 1, 1, 1,
                  1, 0, 0, 0, 
                  1, 0, 0, 0,
                  1, 1, 1, 1, 
                  1, 0, 0, 0, 
                  1, 0, 0, 0,
                  1, 0, 0, 0, 
                  1, 0, 0, 0,};

    int lG[32] = {0, 1, 1, 1,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 1, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1, 
                  0, 1, 1, 0};

    int lH[32] = {1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 1, 1, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lI[32] = {1, 1, 1, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  1, 1, 1, 0};

    int lJ[32] = {1, 1, 1, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1, 
                  0, 0, 0, 1, 
                  0, 0, 0, 1,
                  1, 1, 1, 0};

    int lK[32] = {1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 1, 0,
                  1, 0, 1, 0,
                  1, 1, 0, 0,
                  1, 0, 1, 0,
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lL[32] = {1, 0, 0, 0, 
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0, 
                  1, 0, 0, 0,
                  1, 1, 1, 1};

    int lM[32] = {1, 0, 0, 1, 
                  1, 1, 1, 1, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1,
                  1, 0, 0, 1, 
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lN[32] = {1, 0, 0, 1,
                  1, 1, 0, 1,
                  1, 1, 0, 1,
                  1, 0, 1, 1,
                  1, 0, 1, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lO[32] = {0, 1, 1, 0,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  0, 1, 1, 0};

    int lP[32] = {1, 1, 1, 0,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 1, 1, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0};

    int lQ[32] = {0, 1, 1, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  0, 1, 1, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1};

    int lR[32] = {1, 1, 1, 0,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 1, 1, 0,
                  1, 1, 0, 0, 
                  1, 0, 1, 0,
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lS[32] = {0, 1, 1, 1,
                  1, 0, 0, 0,
                  1, 0, 0, 0, 
                  0, 1, 1, 0,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  1, 1, 1, 0};
    
    int lT[32] = {1, 1, 1, 0, 
                  0, 1, 0, 0, 
                  0, 1, 0, 0, 
                  0, 1, 0, 0, 
                  0, 1, 0, 0, 
                  0, 1, 0, 0, 
                  0, 1, 0, 0, 
                  0, 1, 0, 0};

    int lU[32] = {1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  0, 1, 1, 0};

    int lV[32] = {1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  0, 1, 1, 0,
                  0, 1, 1, 0};

    int lW[32] = {1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 1, 1, 1,
                  1, 0, 0, 1};

    int lX[32] = {1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  0, 1, 1, 0,
                  0, 1, 1, 0,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1};

    int lY[32] = {1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  1, 0, 0, 1, 
                  0, 1, 1, 1, 
                  0, 0, 0, 1,
                  0, 0, 0, 1, 
                  0, 0, 0, 1, 
                  1, 1, 1, 0};

    int lZ[32] = {1, 1, 1, 1,
                  0, 0, 0, 1,
                  0, 0, 0, 1,
                  0, 0, 1, 0,
                  0, 0, 1, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0, 
                  1, 1, 1, 1};

    int sAT[32] = {0, 1, 1, 0,
                   1, 0, 0, 1,
                   1, 0, 0, 1,
                   1, 0, 1, 1,
                   1, 0, 1, 1,
                   1, 0, 1, 1,
                   1, 0, 0, 0,
                   0, 1, 1, 1};

    int sUS[32] = {0, 0, 0, 0, 
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   1, 1, 1, 1};
    int i;
    for(i = 0; i < 32; i++)
    {
        FontEnglish.A[i] = lA[i];
        FontEnglish.B[i] = lB[i];
        FontEnglish.C[i] = lC[i];
        FontEnglish.D[i] = lD[i];
        FontEnglish.E[i] = lE[i];
        FontEnglish.F[i] = lF[i];
        FontEnglish.G[i] = lG[i];
        FontEnglish.H[i] = lH[i];
        FontEnglish.I[i] = lI[i];
        FontEnglish.J[i] = lJ[i];
        FontEnglish.K[i] = lK[i];
        FontEnglish.L[i] = lL[i];
        FontEnglish.M[i] = lM[i];
        FontEnglish.N[i] = lN[i];
        FontEnglish.O[i] = lO[i];
        FontEnglish.P[i] = lP[i];
        FontEnglish.Q[i] = lQ[i];
        FontEnglish.R[i] = lR[i];
        FontEnglish.S[i] = lS[i];
        FontEnglish.T[i] = lT[i];
        FontEnglish.U[i] = lU[i];
        FontEnglish.V[i] = lV[i];
        FontEnglish.W[i] = lW[i];
        FontEnglish.X[i] = lX[i];
        FontEnglish.Y[i] = lY[i];
        FontEnglish.Z[i] = lZ[i];
        FontEnglish.at[i] = sAT[i];
        FontEnglish.us[i] = sUS[i];
    }
}

void SetPixel(int x, int y, unsigned char color)
{
    int offset = VGA_MEMORY + (y * 320 + x);
    *(char*)offset = color;
    return;
}

void PrintC(char c, int x, int y, int color)
{
    int letter[32];
    int i;
    switch(c)
    {
        case 'A':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.A[i];
        }
        break;
        case 'B':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.B[i];
        }
        break;
        case 'C':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.C[i];
        }
        break;
        case 'D':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.D[i];
        }
        break;
        case 'E':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.E[i];
        }
        break;
        case 'F':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.F[i];
        }
        break;
        case 'G':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.G[i];
        }
        break;
        case 'H':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.H[i];
        }
        break;
        case 'I':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.I[i];
        }
        break;
        case 'J':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.J[i];
        }
        break;
        case 'K':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.K[i];
        }
        break;
        case 'L':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.L[i];
        }
        break;
        case 'M':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.M[i];
        }
        break;
        case 'N':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.N[i];
        }
        break;
        case 'O':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.O[i];
        }
        break;
        case 'P':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.P[i];
        }
        break;
        case 'Q':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.Q[i];
        }
        break;
        case 'R':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.R[i];
        }
        break;
        case 'S':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.S[i];
        }
        break;
        case 'T':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.T[i];
        }
        break;
        case 'U':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.U[i];
        }
        break;
        case 'V':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.V[i];
        }
        break;
        case 'W':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.W[i];
        }
        break;
        case 'X':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.X[i];
        }
        break;
        case 'Y':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.Y[i];
        }
        break;
        case 'Z':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.Z[i];
        }
        break;
        case '@':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.at[i];
        }
        break;
        case '_':
        for(i = 0; i < 32; i++)
        {
            letter[i] = FontEnglish.us[i];
        }
        break;
        case '~':
        for(i = 0; i < 32; i++)
        {
            letter[i] = 2;
        }
        break;
    }

    int x1, y1, offset;
    for(y1 = 0; y1 < 8; y1++)
    {
        for(x1 = 0; x1 < 4; x1++)
        {
            offset = y1 * 4 + x1;
            if(letter[offset] == 1) SetPixel(x + x1, y + y1, color);
            if(letter[offset] == 2) SetPixel(x + x1, y + y1, 0);
        }
    }
    for(i = 0; i < 32; i++)
    {
        letter[i] = 0;
    }
    return;
}

void print(const char* str, int x, int y, char color)
{
    int offset = 0;
    while(*str)
    {
        PrintC(*str, x + offset, y, color);
        offset += 5;
        str++;
    }
    return;
}

void ClearScreen(char color)
{
    int i, offset;
    for(i = 0; i <= SCREEN_SIZE; i++)
    {
        offset = VGA_MEMORY + i;
        *(char*)offset = color;
    }
    return;
}

void VGA_TEST()
{
    int i, j;
    for(i = 0;i < 320;i++)
    {
        for(j = 0;j < 200;j++)
        {
            SetPixel(i, j, i % 256);
        }
    }
    return;
}


#endif