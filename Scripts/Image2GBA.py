import sys
from PIL import Image
from GBAPalette import format_rgb

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

img_output_path = "source/background.h"

with open(img_output_path, "w") as file:
    file.write("/* Background Image Data */\n\n")

    file.write("const unsigned short image[38400] = {\n    ")
    line_length = 0
    for i, pixel in enumerate(img_pixels, 1):
        file.write(f"{pixel}, ")
        line_length += len(str(pixel)) + 2
        
        if line_length > 90:
            file.write("\n    ")
            line_length = 0

    file.write("\n};\n")

print(f"Image data saved to {img_output_path}")
