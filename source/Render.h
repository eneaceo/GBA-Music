#ifndef RENDER_H
#define RENDER_H

#define SCREEN ((unsigned short*)MEM_VRAM)

void PlotPixel(unsigned char aX, unsigned char aY, unsigned short aColor);

unsigned short SetColor(unsigned char aR, unsigned char aG, unsigned char aB);

void PlotString(const char aString[], unsigned char aSize, unsigned char x, unsigned char y, unsigned short aColor);

void PlotLetter(unsigned char aIndex, unsigned char aX, unsigned char aY, unsigned short aColor);

void PlotBackground();

#endif