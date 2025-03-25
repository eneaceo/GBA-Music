#include "tonc.h"
#include "AAS.h"

#include "Render.h"
#include "Album.h"


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

void ProcessInput(char *aSongIndex, char *aSongPlayed)
{
    key_poll();

    if (key_hit(KEY_ANY))
    {
        if (key_hit(KEY_A))
        {
            AAS_SFX_Play(0, 64, 8000, SongStart[(unsigned char) *aSongIndex], SongEnd[(unsigned char) *aSongIndex], AAS_NULL);
            AAS_SFX_Play(1, 64, 8000, SongStart[(unsigned char) *aSongIndex], SongEnd[(unsigned char) *aSongIndex], AAS_NULL);
            *aSongPlayed = *aSongIndex;
        }
        else if (key_hit(KEY_DOWN))
        {
            *aSongIndex = (*aSongIndex + 1) % 6;
        }
        else if (key_hit(KEY_UP))
        {
            *aSongIndex = (*aSongIndex - 1 + 6) % 6;
        }
    }
}

unsigned short GetTitleColor(const char aSongIndex, const char aSongPlaying, const char aIndex)
{
    unsigned short Color = CLR_WHITE;

    if (aIndex == aSongPlaying)
    {
        Color = CLR_ORANGE;
    } 
    else if (aIndex == aSongIndex)
    {
        Color = CLR_YELLOW;
    }

    return Color;
}

int main()
{
    InitSystem();
    InitAlbum();
    PlotBackground();

    char SongIndex = 0;
    char SongPlaying = -1;

    while (1)
    {
        ProcessInput(&SongIndex, &SongPlaying);
        
        int text_size = 30;
        PlotString("DISFORIA*", text_size, 60, 5, GetTitleColor(SongIndex, SongPlaying, 0));
        PlotString("FOTO DE UN CABALLO*", text_size, 60, 15, GetTitleColor(SongIndex, SongPlaying, 1));
        PlotString("DE INTERNET SE SALE*", text_size, 60, 25, GetTitleColor(SongIndex, SongPlaying, 2));
        PlotString("CAPTCHA*", text_size, 60, 35, GetTitleColor(SongIndex, SongPlaying, 3));
        PlotString("PARKING TANATORIO*", text_size, 60, 45, GetTitleColor(SongIndex, SongPlaying, 4));
        PlotString("POSTURA*", text_size, 60, 55, GetTitleColor(SongIndex, SongPlaying, 5));

        VBlankIntrWait();
    }

    return 0;
}
