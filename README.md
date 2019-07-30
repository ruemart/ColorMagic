# ColorMagic
C++ Library that allows manipulation and conversion of colors. 

# Color Spaces
* RGB (0 - 255 and 0 - 1) including alpha
* Grey (0 - 255 and 0 - 1) including alpha
* CMYK (0 - 1)
* HSV (0 - 359 / 0 - 1)
* HSL (0 - 359 / 0 - 1)
* XYZ (0 - 100)
* XYY (0 - 100)
* CieLUV (0 - 100 / -100 - 100)
* Lab (-128 - 128)

# Color Manipulations:
* Converting from each color space to any other one
* Adding, mixing, averaging and subtracting colors (optionally with weights)
* Calculating color distances (Euclidean, CMC, CIELAB76, CIELAB94, CIELAB2000)
* Creating color sets (Complementary, Triplet, Quartet, Quintet, Analogous, Complementary Split, Custom)
* Adjusting colors (Saturate, Desaturate, Lighten, Unlighten)

# Color Theory
* RGB Color Space Definitions (sRGB, AdobeRGB, custom ones, ...)
* White Points (A, B, C, E, F, D, custom ones)
* Gamma Functions (sRGB, AdobeRGB, custom ones, ...)
