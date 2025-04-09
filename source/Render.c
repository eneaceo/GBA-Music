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
    return (aR & 0x1F) | ((aG & 0x1F) << 5) | ((aB & 0x1F) << 10);
}

void PlotString(const char aString[], unsigned char aSize, unsigned char aX, unsigned char aY, unsigned short aColor)
{
    for (unsigned char i = 0; i < aSize; i++) {
        char letter = aString[i];
        if (letter == '*') return;
        if (letter >= 'A' && letter <= 'Z') {
            if (letter - 'A' == 8)
                aX -= 3;
            PlotLetter(letter - 'A', aX, aY, aColor);
        }
        aX += 8;
    }
}

void PlotLetter(unsigned char aIndex, unsigned char aX, unsigned char aY, unsigned short aColor)
{
    const unsigned short* Letter = Letters[aIndex];
    for (unsigned char i = 0; i < 5; i++)
    {
        unsigned char Num = Letter[i];
        for (unsigned char Bit = 0; Bit < 8; Bit++)
        {
            if ((Num >> Bit) & 1)
                PlotPixel(aX + (7 - Bit), aY + i, aColor);
        }
    }
}

void PlotBackground()
{
    for (unsigned char i = 0; i < 160; i++)
    {
        for (unsigned char j = 0; j < 240; j++)
        {
            PlotPixel(j, i, Background[i * 240 + j]);
        }
    }
}