#ifndef TGA_H
#define TGA_H
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

typedef struct
{
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
} tga_hlavicka;

typedef struct
{
    byte b;
    byte g;
    byte r;
    byte a;
} pixel;

void prevod_na_byte(byte pole[2], int hodnota);
void inicializuj_hlavicku(tga_hlavicka *h, int sirka, int vyska);
int uloz_obrazek(const char *cesta, tga_hlavicka *h, pixel *obrazek, int sirka, int vyska);

#endif
