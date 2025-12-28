#ifndef KRESLENI_H
#define KRESLENI_H
#include "tga.h"

void nastav_pixel(int x, int y, byte r0, byte g0, byte b0, byte a0, pixel *obrazek, int sirka, int vyska);

void kresli_caru(int x1, int y1, int x2, int y2, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska);

void kresli_obdelnik(int x, int y, int w, int h, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska);

void kresli_kruh(int x, int y, int p, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska);

void kresli_trojuhelnik(int x, int y, int s, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska);

void kresli_otoceny_obdelnik(float uhel_stupne, int cx, int cy, int w, int h, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska);

#endif
