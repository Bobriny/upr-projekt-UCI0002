#ifndef PRIKAZY_H
#define PRIKAZY_H
#include "tga.h"
#include "kresleni.h"

int zpracuj_prikaz(char *radek, pixel *obrazek, int sirka, int vyska, tga_hlavicka *hlavicka, const char *cesta_vystup);

#endif
