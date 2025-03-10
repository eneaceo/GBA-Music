# Convert RGB to 16-bit color format
def format_rgb(r, g, b):
    return ((r * 31 // 255) & 0x1F) | (((g * 31 // 255) & 0x1F) << 5) | (((b * 31 // 255) & 0x1F) << 10)

palette = {
    "WHITE":        format_rgb(255, 255, 255),
    "BLACK":        format_rgb(0, 0, 0),
    "LIGHTGREY":    format_rgb(192, 192, 192),
    "DARKGREY":     format_rgb(128, 128, 128),
    "GREY":         format_rgb(160, 160, 160),
    
    "RED":          format_rgb(255, 0, 0),
    "DARKRED":      format_rgb(139, 0, 0),
    "LIGHTRED":     format_rgb(255, 102, 102),
    "CRIMSON":      format_rgb(220, 20, 60),
    "MAROON":       format_rgb(128, 0, 0),
    
    "GREEN":        format_rgb(0, 255, 0),
    "DARKGREEN":    format_rgb(0, 128, 0),
    "LIGHTGREEN":   format_rgb(144, 238, 144),
    "FORESTGREEN":  format_rgb(34, 139, 34),
    "EMERALD":      format_rgb(80, 200, 120),
    
    "BLUE":         format_rgb(0, 0, 255),
    "DARKBLUE":     format_rgb(0, 0, 139),
    "LIGHTBLUE":    format_rgb(173, 216, 230),
    "SKYBLUE":      format_rgb(135, 206, 235),
    "ROYALBLUE":    format_rgb(65, 105, 225),
    "MIDNIGHTBLUE": format_rgb(25, 25, 112),
    
    "ORANGE":       format_rgb(255, 128, 0),
    "DARKORANGE":   format_rgb(255, 140, 0),
    "LIGHTORANGE":  format_rgb(255, 200, 120),
    "BURNTORANGE":  format_rgb(204, 85, 0),
    
    "YELLOW":       format_rgb(255, 255, 0),
    "GOLD":         format_rgb(255, 215, 0),
    "LIGHTYELLOW":  format_rgb(255, 255, 153),
    "MUSTARD":      format_rgb(204, 179, 0),
    
    "LIME":         format_rgb(128, 255, 0),
    "DARKLIME":     format_rgb(50, 205, 50),
    
    "CYAN":         format_rgb(0, 255, 255),
    "DARKCYAN":     format_rgb(0, 139, 139),
    "LIGHTCYAN":    format_rgb(224, 255, 255),
    "AQUA":         format_rgb(0, 255, 204),
    
    "PURPLE":       format_rgb(127, 0, 255),
    "DARKPURPLE":   format_rgb(75, 0, 130),
    "LIGHTPURPLE":  format_rgb(216, 191, 216),
    "LAVENDER":     format_rgb(230, 230, 250),
    "VIOLET":       format_rgb(238, 130, 238),
    
    "MAGENTA":      format_rgb(255, 0, 255),
    "PINK":         format_rgb(255, 192, 203),
    "DEEPPINK":     format_rgb(255, 20, 147),
    "HOTPINK":      format_rgb(255, 105, 180),
    
    "BROWN":        format_rgb(139, 69, 19),
    "DARKBROWN":    format_rgb(101, 67, 33),
    "TAN":          format_rgb(210, 180, 140),
    "CHOCOLATE":    format_rgb(210, 105, 30),
    
    "NAVY":         format_rgb(0, 0, 128),
    "TEAL":         format_rgb(0, 128, 128),
    "OLIVE":        format_rgb(128, 128, 0),
    "TURQUOISE":    format_rgb(64, 224, 208),
    
    "BEIGE":        format_rgb(245, 245, 220),
    "MINT":         format_rgb(189, 252, 201),
    "SALMON":       format_rgb(250, 128, 114),
    "CORAL":        format_rgb(255, 127, 80),
    "PEACH":        format_rgb(255, 218, 185),
}

colors_output_path = "source/colors.h"

with open(colors_output_path, "w") as file:
    file.write("/* Available Colors Data */\n\n")

    file.write("enum COLORS\n{\n")
    for color, value in palette.items():
        file.write(f"    {color} = {value},\n")
    file.write("};\n\n")

print(f"Available colors data saved to {colors_output_path}")
