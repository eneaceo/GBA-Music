#ifndef ALBUM_H
#define ALBUM_H

/* This file is an example of how Album.h should look like */
/* Running the python script Album2GBA.py will generate it if .raw files are found in the AAS_Data folder */

/* Script Generated Header*/
/* Album Data */

#include "../AAS_Data.h"

#define SONGNUMBER 6
#define TITLEMAXSIZE 20

const AAS_s8* SongStart[SONGNUMBER];
const AAS_s8* SongEnd[SONGNUMBER];

const unsigned char PositionXTitleStart = 60;
const unsigned char PositionYTitleStart = 5;
const unsigned char SongTitleSeparation = 10;

const char SongTitle[SONGNUMBER][TITLEMAXSIZE] = {
   "DISFORIA*",
   "FOTO DE UN CABALLO*",
   "DE INTERNET SE SALE*",
   "CAPTCHA*",
   "PARKING TANATORIO*",
   "POSTURA*",
};

void InitAlbum() {
   SongStart[0] = AAS_DATA_SFX_START_fotocopia_01_Disforia;
   SongStart[1] = AAS_DATA_SFX_START_fotocopia_02_Foto_de_un_caballo;
   SongStart[2] = AAS_DATA_SFX_START_fotocopia_03_De_Internet_se_sale;
   SongStart[3] = AAS_DATA_SFX_START_fotocopia_04_Captcha;
   SongStart[4] = AAS_DATA_SFX_START_fotocopia_05_Parking_Tanatorio;
   SongStart[5] = AAS_DATA_SFX_START_fotocopia_06_Postura;
   SongEnd[0] = AAS_DATA_SFX_END_fotocopia_01_Disforia;
   SongEnd[1] = AAS_DATA_SFX_END_fotocopia_02_Foto_de_un_caballo;
   SongEnd[2] = AAS_DATA_SFX_END_fotocopia_03_De_Internet_se_sale;
   SongEnd[3] = AAS_DATA_SFX_END_fotocopia_04_Captcha;
   SongEnd[4] = AAS_DATA_SFX_END_fotocopia_05_Parking_Tanatorio;
   SongEnd[5] = AAS_DATA_SFX_END_fotocopia_06_Postura;
}

#endif