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

void PlaySong(char *aSongIndex, char *aSongPlaying, bool *aPlaying)
{
    AAS_SFX_Play(0, 64, 8000, SongStart[(unsigned char) *aSongIndex], SongEnd[(unsigned char) *aSongIndex], AAS_NULL);
    AAS_SFX_Play(1, 64, 8000, SongStart[(unsigned char) *aSongIndex], SongEnd[(unsigned char) *aSongIndex], AAS_NULL);
    *aSongPlaying = *aSongIndex;
    *aPlaying = true;
}

void ProcessInput(char *aSongIndex, char *aSongPlaying, bool *aPlaying)
{
    key_poll();

    if (key_hit(KEY_ANY))
    {
        if (key_hit(KEY_A))
        {
            PlaySong(aSongIndex, aSongPlaying, aPlaying);
        }
        else if (key_hit(KEY_B))
        {
            AAS_SFX_Stop(0);
            AAS_SFX_Stop(1);
            *aPlaying = false;
        }
        else if (key_hit(KEY_DOWN))
        {
            *aSongIndex = (*aSongIndex + 1) % SONGNUMBER;
        }
        else if (key_hit(KEY_UP))
        {
            *aSongIndex = (*aSongIndex - 1 + SONGNUMBER) % SONGNUMBER;
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
    bool Playing = false;

    while (1)
    {
        ProcessInput(&SongIndex, &SongPlaying, &Playing);
        if (!Playing)
        {
            SongPlaying = -1;
        }
        else if (!AAS_SFX_IsActive(0))
        {
            SongPlaying++;
            if (SongPlaying < SONGNUMBER)
            {
                PlaySong(&SongPlaying, &SongPlaying, &Playing);
            }
            else 
            {
                SongIndex = 0;
                Playing = false;
            }
        }

        for (unsigned char Index = 0; Index < SONGNUMBER; Index++)
        {
            PlotString(SongTitle[Index], TITLEMAXSIZE, PositionXTitleStart, PositionYTitleStart + Index * SongTitleSeparation, GetTitleColor(SongIndex, SongPlaying, Index));
        }

        VBlankIntrWait();
    }

    return 0;
}
