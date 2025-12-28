#include "prikazy.h"
#include <string.h>
#include <stdio.h>

int zpracuj_prikaz(char *radek, pixel *obrazek, int sirka, int vyska, tga_hlavicka *hlavicka, const char *cesta_vystup)
{
    if (strcmp(radek, "save") == 0)
    {
        uloz_obrazek(cesta_vystup, hlavicka, obrazek, sirka, vyska);
        return 0;
    }

    if (strcmp(radek, "exit") == 0)
    {
        uloz_obrazek(cesta_vystup, hlavicka, obrazek, sirka, vyska);
        return 1;
    }

    if (strncmp(radek, "line ", 5) == 0)
    {
        int x1;
        int y1;
        int x2;
        int y2;
        int r;
        int g;
        int b;
        int a;
        if (sscanf(radek + 5, "%d,%d,%d,%d,%d,%d,%d,%d", &x1, &y1, &x2, &y2, &r, &g, &b, &a) != 8)
        {
            printf("chybny pocet argumentu pro line\n");
            return 0;
        }
        kresli_caru(x1, y1, x2, y2, r, g, b, a, obrazek, sirka, vyska);
        return 0;
    }

    if (strncmp(radek, "rectangle ", 10) == 0)
    {
        int x;
        int y;
        int w;
        int h;
        int r;
        int g;
        int b;
        int a;
        if (sscanf(radek + 10, "%d,%d,%d,%d,%d,%d,%d,%d", &x, &y, &w, &h, &r, &g, &b, &a) != 8)
        {
            printf("chybny pocet argumentu pro rectangle\n");
            return 0;
        }
        kresli_obdelnik(x, y, w, h, r, g, b, a, obrazek, sirka, vyska);
        return 0;
    }

    if (strncmp(radek, "circle ", 7) == 0)
    {
        int x;
        int y;
        int p;
        int r;
        int g;
        int b;
        int a;
        if (sscanf(radek + 7, "%d,%d,%d,%d,%d,%d,%d", &x, &y, &p, &r, &g, &b, &a) != 7)
        {
            printf("chybny pocet argumentu pro circle\n");
            return 0;
        }
        kresli_kruh(x, y, p, r, g, b, a, obrazek, sirka, vyska);
        return 0;
    }

    if (strncmp(radek, "triangle ", 9) == 0)
    {
        int x;
        int y;
        int s;
        int r;
        int g;
        int b;
        int a;
        if (sscanf(radek + 9, "%d,%d,%d,%d,%d,%d,%d", &x, &y, &s, &r, &g, &b, &a) != 7)
        {
            printf("chybny pocet argumentu pro triangle\n");
            return 0;
        }
        kresli_trojuhelnik(x, y, s, r, g, b, a, obrazek, sirka, vyska);
        return 0;
    }

    if (strncmp(radek, "rotated-rectangle ", 18) == 0)
    {
        float uhel;
        int x;
        int y;
        int w;
        int h;
        int r;
        int g;
        int b;
        int a;
        if (sscanf(radek + 18, "%f,%d,%d,%d,%d,%d,%d,%d,%d", &uhel, &x, &y, &w, &h, &r, &g, &b, &a) != 9)
        {
            printf("chybny pocet argumentu pro rotated-rectangle\n");
            return 0;
        }
        kresli_otoceny_obdelnik(uhel, x, y, w, h, r, g, b, a, obrazek, sirka, vyska);
        return 0;
    }

    printf("neznamy prikaz: %s\n", radek);
    return 0;
}
