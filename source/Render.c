#include "Render.h"

void PlotPixel(u8 aX, u8 aY, u16 aColor)
{
    SCREEN[aY * 240 + aX] = aColor;
}

u16 SetColor(u8 aR, u8 aG, u8 aB)
{
    return (aR & 0x1F) | (aG & 0x1F) << 5 | (aB & 0x1F) << 10;
}