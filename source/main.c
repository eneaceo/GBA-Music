#include "tonc.h"
#include "AAS.h"
#include "../AAS_Data.h"

#include "colors.h"
#include "background.h"

#define REG_KEY (*(volatile AAS_u16 *)0x04000130)
#define REG_KEY_A 0x0001
#define REG_KEY_B 0x0002

#define BUFFER ((u16 *)0x6000000)


void PlotPixel(u8 aX, u8 aY, u16 aColor)
{
    BUFFER[aY * 240 + aX] = aColor;
}

u16 SetColor(u8 aR, u8 aG, u8 aB)
{
    return (aR & 0x1F) | (aG & 0x1F) << 5 | (aB & 0x1F) << 10;
}

void init_main()
{
    // Set display mode to 3
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

    // AAS initialization
    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    irq_add(II_TIMER1, AAS_Timer1InterruptHandler);
    AAS_SetConfig(AAS_CONFIG_MIX_32KHZ, AAS_CONFIG_CHANS_8, AAS_CONFIG_SPATIAL_STEREO, AAS_CONFIG_DYNAMIC_OFF);
}

int main()
{

    const AAS_s8 *const album_start[6] = {
        AAS_DATA_SFX_START_fotocopia_001,
        AAS_DATA_SFX_START_fotocopia_002,
        AAS_DATA_SFX_START_fotocopia_003,
        AAS_DATA_SFX_START_fotocopia_004,
        AAS_DATA_SFX_START_fotocopia_005,
        AAS_DATA_SFX_START_fotocopia_006};
    
    const AAS_s8 *const album_end[6] = {
        AAS_DATA_SFX_END_fotocopia_001,
        AAS_DATA_SFX_END_fotocopia_002,
        AAS_DATA_SFX_END_fotocopia_003,
        AAS_DATA_SFX_END_fotocopia_004,
        AAS_DATA_SFX_END_fotocopia_005,
        AAS_DATA_SFX_END_fotocopia_006};
    
    int SongIndex = 0;

    int keys, keys_changed;
    int prev_keys = 0;
    init_main();

    for (int i = 0; i < 160; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            PlotPixel(j, i, image[i * 240 + j]);
        }
    }

    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 120; j++)
        {
            PlotPixel(j, i, BLACK);
        }
    }

    const u8 letter_A[8] = {0, 24, 36, 36, 60, 36, 36, 0};
    u8 size = 8;
    int x = 40;
    int y = 40;
    for (int i = 0; i < size; i++)
    {
        int num = letter_A[i];
        for (int bit = 7; bit >= 0; bit--)
        {
            if ((num >> bit) & 1)
            {
                PlotPixel(x + bit, y + i, WHITE);
            }
        }
    }

    while (1)
    {
        keys = ~REG_KEY;
        keys_changed = keys ^ prev_keys;
        prev_keys = keys;
      
        if ((keys_changed & REG_KEY_A) && (keys & REG_KEY_A)) {
            AAS_SFX_Play(0, 64, 8000, album_start[SongIndex], album_end[SongIndex], AAS_NULL);
            AAS_SFX_Play(1, 64, 8000, album_start[SongIndex], album_end[SongIndex], AAS_NULL);
        }
    
        if ((keys_changed & REG_KEY_B) && (keys & REG_KEY_B)) {
          SongIndex = (SongIndex + 1) % 6;
        }
    

        VBlankIntrWait();
    }

    return 0;
}
