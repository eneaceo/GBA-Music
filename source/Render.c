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
    for (unsigned char c = 0; c < aSize; c++)
    {
        char Letter = aString[c];
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
    const unsigned short* letter = letters[aIndex];
    for (int i = 0; i < 8; i++)
    {
        int num = letter[i];
        for (int bit = 0; bit < 8; bit++)
        {
            if ((i == 0 && bit == 0) || (i == 7 && bit == 7))
                continue;

            PlotPixel(aX + (7 - bit), aY + i, ((num >> bit) & 1 ? CLR_BLACK : aColor));
        }
    }
}

void PlotBackground()
{
    for (int i = 0; i < 160; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            PlotPixel(j, i, Background[i * 240 + j]);
        }
    }
}