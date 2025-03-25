#include "tonc.h"

#include "Render.h"
#include "Font.h"
#include "Background.h"

void PlotPixel(unsigned char aX, unsigned char aY, unsigned short aColor)
{
    SCREEN[aY * 240 + aX] = aColor;
}

unsigned short SetColor(unsigned char aR, unsigned char aG, unsigned char aB)
{
    return (aR & 0x1F) | (aG & 0x1F) << 5 | (aB & 0x1F) << 10;
}

void PlotString(char aString[], unsigned char aSize, unsigned char aX, unsigned char aY, unsigned short aColor)
{
    for (unsigned char C = 0; C < aSize; C++)
    {
        char Letter = aString[C];
            switch (Letter) {
                case 'A': PlotLetter(0, aX, aY, aColor); break;
                case 'B': PlotLetter(1, aX, aY, aColor); break;
                case 'C': PlotLetter(2, aX, aY, aColor); break;
                case 'D': PlotLetter(3, aX, aY, aColor); break;
                case 'E': PlotLetter(4, aX, aY, aColor); break;
                case 'F': PlotLetter(5, aX, aY, aColor); break;
                case 'G': PlotLetter(6, aX, aY, aColor); break;
                case 'H': PlotLetter(7, aX, aY, aColor); break;
                case 'I': PlotLetter(8, aX, aY, aColor); break;
                case 'J': PlotLetter(9, aX, aY, aColor); break;
                case 'K': PlotLetter(10, aX, aY, aColor); break;
                case 'L': PlotLetter(11, aX, aY, aColor); break;
                case 'M': PlotLetter(12, aX, aY, aColor); break;
                case 'N': PlotLetter(13, aX, aY, aColor); break;
                case 'O': PlotLetter(14, aX, aY, aColor); break;
                case 'P': PlotLetter(15, aX, aY, aColor); break;
                case 'Q': PlotLetter(16, aX, aY, aColor); break;
                case 'R': PlotLetter(17, aX, aY, aColor); break;
                case 'S': PlotLetter(18, aX, aY, aColor); break;
                case 'T': PlotLetter(19, aX, aY, aColor); break;
                case 'U': PlotLetter(20, aX, aY, aColor); break;
                case 'V': PlotLetter(21, aX, aY, aColor); break;
                case 'W': PlotLetter(22, aX, aY, aColor); break;
                case 'X': PlotLetter(23, aX, aY, aColor); break;
                case 'Y': PlotLetter(24, aX, aY, aColor); break;
                case 'Z': PlotLetter(25, aX, aY, aColor); break;
                case '*': return; break;
                default: break;
            }

        aX += 9;
    }
}

void PlotLetter(unsigned char aIndex, unsigned char aX, unsigned char aY, unsigned short aColor)
{
    const unsigned short* Letter = Letters[aIndex];
    for (unsigned char I = 0; I < 8; I++)
    {
        unsigned char Num = Letter[I];
        for (unsigned char Bit = 0; Bit < 8; Bit++)
        {
            if ((I == 0 && Bit == 0) || (I == 7 && Bit == 7))
                continue;

            PlotPixel(aX + (7 - Bit), aY + I, ((Num >> Bit) & 1 ? CLR_BLACK : aColor));
        }
    }
}

void PlotBackground()
{
    for (unsigned char I = 0; I < 160; I++)
    {
        for (unsigned char J = 0; J < 240; J++)
        {
            PlotPixel(J, I, Background[I * 240 + J]);
        }
    }
}