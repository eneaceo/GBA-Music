#ifndef ALBUM_H
#define ALBUM_H

#include "../AAS_Data.h"

const AAS_s8* SongStart[6];
const AAS_s8* SongEnd[6];

void InitAlbum()
{
    SongStart[0] = AAS_DATA_SFX_START_fotocopia_001;
    SongStart[1] = AAS_DATA_SFX_START_fotocopia_002;
    SongStart[2] = AAS_DATA_SFX_START_fotocopia_003;
    SongStart[3] = AAS_DATA_SFX_START_fotocopia_004;
    SongStart[4] = AAS_DATA_SFX_START_fotocopia_005;
    SongStart[5] = AAS_DATA_SFX_START_fotocopia_006;

    SongEnd[0] = AAS_DATA_SFX_END_fotocopia_001;
    SongEnd[1] = AAS_DATA_SFX_END_fotocopia_002;
    SongEnd[2] = AAS_DATA_SFX_END_fotocopia_003;
    SongEnd[3] = AAS_DATA_SFX_END_fotocopia_004;
    SongEnd[4] = AAS_DATA_SFX_END_fotocopia_005;
    SongEnd[5] = AAS_DATA_SFX_END_fotocopia_006;
}

#endif