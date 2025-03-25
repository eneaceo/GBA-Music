import sys
from PIL import Image

# Convert RGB to 16-bit color format
def format_rgb(r, g, b):
    return ((r * 31 // 255) & 0x1F) | (((g * 31 // 255) & 0x1F) << 5) | (((b * 31 // 255) & 0x1F) << 10)

SIZE = (240, 160)

if len(sys.argv) < 2:
    print("[ERROR]: Image path needed!")
    sys.exit()

img_path = sys.argv[1]
try:
    img = Image.open(img_path)
except FileNotFoundError:
    print(f"[ERROR]: {img_path} file not found!")
    sys.exit()

img = img.resize(SIZE, Image.Resampling.LANCZOS).convert("RGB")
img.save("preview.jpg")

img_pixels = [format_rgb(r, g, b) for r, g, b in img.getdata()]

img_output_path = "source/Background.h"

with open(img_output_path, "w") as file:
    file.write("#ifndef BACKGROUND_H\n")
    file.write("#define BACKGROUND_H\n\n")
    
    file.write("/* Script Generated Header*/\n")
    file.write("/* Background Image Data */\n\n")


    file.write("const unsigned short Background[38400] = {\n    ")
    line_length = 0
    for i, pixel in enumerate(img_pixels, 1):
        file.write(f"{pixel}, ")
        line_length += len(str(pixel)) + 2
        
        if line_length > 90:
            file.write("\n    ")
            line_length = 0

    file.write("\n};\n\n")
    file.write("#endif")

print(f"Image data saved to {img_output_path}")
