#ifndef RENDER_H
#define RENDER_H

#include "tonc.h"

#define SCREEN ((u16*)MEM_VRAM)

void PlotPixel(u8 aX, u8 aY, u16 aColor);

u16 SetColor(u8 aR, u8 aG, u8 aB);

#endif