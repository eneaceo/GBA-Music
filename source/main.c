#include "tonc.h"
#include "AAS.h"

#include "Render.h"
// Script generated includes.
#include "Background.h"
#include "Album.h"


#define REG_KEY (*(volatile AAS_u16 *)0x04000130)
#define REG_KEY_A 0x0001
#define REG_KEY_B 0x0002


void InitSystem()
{
    // Set display mode to 3. 
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

    // AAS initialization
    // Enable vblank interrupt
    REG_DISPSTAT |= 0x8;
    REG_IE |= 0x1;
    // Initialise AAS
    AAS_SetConfig(AAS_CONFIG_MIX_32KHZ, AAS_CONFIG_CHANS_8, AAS_CONFIG_SPATIAL_STEREO, AAS_CONFIG_DYNAMIC_OFF);
    // Set up the interrupt handlers
    irq_init(NULL);
    // set timer 1 to AAS_FastTimer1InterruptHandler()
    irq_add(II_TIMER1, AAS_FastTimer1InterruptHandler);
    // call AAS_DoWork() during vblank
    irq_add(II_VBLANK, AAS_DoWork);
}

int main()
{
    InitSystem();
    InitAlbum();

    int SongIndex = 0;

    int keys, keys_changed;
    int prev_keys = 0;

    for (int i = 0; i < 160; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            PlotPixel(j, i, image[i * 240 + j]);
        }
    }

    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            PlotPixel(j, i, CLR_BLACK);
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
                PlotPixel(x + bit, y + i, CLR_WHITE);
            }
        }
    }

    while (1)
    {
        keys = ~REG_KEY;
        keys_changed = keys ^ prev_keys;
        prev_keys = keys;

        if ((keys_changed & REG_KEY_A) && (keys & REG_KEY_A))
        {
            AAS_SFX_Play(0, 64, 8000, SongStart[SongIndex], SongEnd[SongIndex], AAS_NULL);
            AAS_SFX_Play(1, 64, 8000, SongStart[SongIndex], SongEnd[SongIndex], AAS_NULL);
        }

        if ((keys_changed & REG_KEY_B) && (keys & REG_KEY_B))
        {
            SongIndex = (SongIndex + 1) % 6;
        }
        
        VBlankIntrWait();
    }

    return 0;
}
