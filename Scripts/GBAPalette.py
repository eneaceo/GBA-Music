# Convert RGB to 16-bit color format
def format_rgb(r, g, b):
    return ((r * 31 // 255) & 0x1F) | (((g * 31 // 255) & 0x1F) << 5) | (((b * 31 // 255) & 0x1F) << 10)

palette = {
    "WHITE":        format_rgb(255, 255, 255),
    "BLACK":        format_rgb(0, 0, 0),
    "LIGHTGREY":    format_rgb(192, 192, 192),
    "DARKGREY":     format_rgb(128, 128, 128),
    "RED":          format_rgb(255, 0, 0),
    "GREEN":        format_rgb(0, 255, 0),
    "BLUE":         format_rgb(0, 0, 255),
    "ORANGE":       format_rgb(255, 128, 0),
    "YELLOW":       format_rgb(255, 255, 0),
    "LIME":         format_rgb(128, 255, 0),
    "CYAN":         format_rgb(0, 255, 255),
    "PURPLE":       format_rgb(127, 0, 255),
    "MAGENTA":      format_rgb(255, 0, 255),
}

colors_output_path = "source/colors.h"

with open(colors_output_path, "w") as file:
    file.write("/* Available Colors Data */\n\n")

    file.write("enum COLORS\n{\n")
    for color, value in palette.items():
        file.write(f"    {color} = {value},\n")
    file.write("};\n\n")

print(f"Available colors data saved to {colors_output_path}")
