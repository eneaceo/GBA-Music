import glob
import os
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument("-x", type=int, help="Text start position in X", required = False, default = 5)
parser.add_argument("-y", type=int, help="Text start position in Y", required = False, default = 5)
parser.add_argument("-s", type=int, help="Text separartion", required = False, default = 10)
args = parser.parse_args()

x_start_position = args.x
y_start_position = args.y
text_separation = args.s

files = []
album_folder = os.path.abspath("AAS_Data")
for file in glob.glob(os.path.join(album_folder, "*.raw")):
    files.append(file)

song_number = len(files)

if song_number == 0:
    print("[ERROR]: album files not found!")
    sys.exit()

file_names = []
song_names = []
max_text_size = 0
for file in files:
    file_name_ext = os.path.basename(file)
    file_name = os.path.splitext(file_name_ext)[0]
    song_name = file_name.split('_', 2)[-1]
    song_name = song_name.replace('_', ' ').upper()
    
    text_size = len(song_name)
    if text_size > max_text_size:
        max_text_size = text_size

    file_names.append(file_name)
    song_names.append(song_name)

max_text_size += 1
album_output_path = "source/Album.h"

with open(album_output_path, "w") as file:
    file.write("#ifndef ALBUM_H\n")
    file.write("#define ALBUM_H\n\n")
    
    file.write("/* Script Generated Header*/\n")
    file.write("/* Album Data */\n\n")
    
    file.write("#include \"../AAS_Data.h\"\n\n")

    file.write(f"#define SONGNUMBER {song_number}\n")
    file.write(f"#define TITLEMAXSIZE {max_text_size}\n\n")

    file.write("const AAS_s8* SongStart[SONGNUMBER];\n")
    file.write("const AAS_s8* SongEnd[SONGNUMBER];\n\n")

    file.write(f"const unsigned char PositionXTitleStart = {x_start_position};\n")
    file.write(f"const unsigned char PositionYTitleStart = {y_start_position};\n")
    file.write(f"const unsigned char SongTitleSeparation = {text_separation};\n\n")

    file.write("const char SongTitle[SONGNUMBER][TITLEMAXSIZE] = {\n")
    for song in song_names:
        file.write(f"   \"{song}*\",\n")
    file.write("};\n\n")
    
    file.write("void InitAlbum() {\n")

    for index in range(song_number):
        file.write(f"   SongStart[{index}] = AAS_DATA_SFX_START_{file_names[index]};\n")
    for index in range(song_number):
        file.write(f"   SongEnd[{index}] = AAS_DATA_SFX_END_{file_names[index]};\n")
    file.write("}\n\n")


    file.write("#endif")

print(f"Album data saved to {album_output_path}")
