#include "tga.h"

void prevod_na_byte(byte pole[2], int hodnota)
{
    pole[0] = hodnota & 0xFF;
    pole[1] = (hodnota >> 8) & 0xFF;
}

void inicializuj_hlavicku(tga_hlavicka *h, int sirka, int vyska)
{
    h->id_length = 0;
    h->color_map_type = 0;
    h->image_type = 2;

    for (int i = 0; i < 5; i++)
        h->color_map[i] = 0;

    prevod_na_byte(h->x_origin, 0);
    prevod_na_byte(h->y_origin, 0);
    prevod_na_byte(h->width, sirka);
    prevod_na_byte(h->height, vyska);

    h->depth = 32;
    h->descriptor = 0x20;
}

int uloz_obrazek(const char *cesta, tga_hlavicka *h, pixel *obrazek, int sirka, int vyska)
{
    FILE *f = fopen(cesta, "wb");
    if (!f)
    {
        printf("chyba: nelze otevrit vystupni soubor\n");
        return 1;
    }

    fwrite(h, sizeof(tga_hlavicka), 1, f);
    fwrite(obrazek, sizeof(pixel), sirka * vyska, f);

    fclose(f);
    return 0;
}
