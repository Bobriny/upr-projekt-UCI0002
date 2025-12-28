#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tga.h"
#include "prikazy.h"

int main(int argc, char *argv[])
{
    char *cesta_vystup = NULL;
    int sirka = 0;
    int vyska = 0;

    int mam_output = 0;
    int mam_width = 0;
    int mam_height = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--output") == 0)
        {
            if (mam_output || i + 1 >= argc)
            {
                printf("spatne parametry\n");
                return 1;
            }
            cesta_vystup = argv[++i];
            mam_output = 1;
        }
        else if (strcmp(argv[i], "--width") == 0)
        {
            if (mam_width || i + 1 >= argc)
            {
                printf("spatne parametry\n");
                return 1;
            }
            sirka = atoi(argv[++i]);
            mam_width = 1;
        }
        else if (strcmp(argv[i], "--height") == 0)
        {
            if (mam_height || i + 1 >= argc)
            {
                printf("spatne parametry\n");
                return 1;
            }
            vyska = atoi(argv[++i]);
            mam_height = 1;
        }
        else
        {
            printf("spatne parametry\n");
            return 1;
        }
    }

    if (!mam_output || !mam_width || !mam_height || sirka <= 0 || vyska <= 0)
    {
        printf("spatne parametry\n");
        return 1;
    }

    int pocet_pixelu = sirka * vyska;
    pixel *obrazek = malloc(pocet_pixelu * sizeof(pixel));
    if (!obrazek)
    {
        printf("chyba: nedostatek pameti\n");
        return 1;
    }

    for (int i = 0; i < pocet_pixelu; i++)
    {
        obrazek[i].r = 0;
        obrazek[i].g = 0;
        obrazek[i].b = 0;
        obrazek[i].a = 255;
    }

    tga_hlavicka hlavicka;
    inicializuj_hlavicku(&hlavicka, sirka, vyska);

    char radek[500];

    while (1)
    {
        if (fgets(radek, sizeof(radek), stdin) == NULL)
        {
            uloz_obrazek(cesta_vystup, &hlavicka, obrazek, sirka, vyska);
            break;
        }

        size_t delka = strlen(radek);
        if (delka > 0 && (radek[delka - 1] == '\n' || radek[delka - 1] == '\r'))
        {
            radek[delka - 1] = '\0';
        }

        if (radek[0] == '\0')
        {
            continue;
        }

        int konec = zpracuj_prikaz(radek, obrazek, sirka, vyska, &hlavicka, cesta_vystup);
        if (konec)
        {
            break;
        }
    }

    free(obrazek);
    return 0;
}
