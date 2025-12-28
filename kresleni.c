#include "kresleni.h"
#include <math.h>

void nastav_pixel(int x, int y, byte r0, byte g0, byte b0, byte a0, pixel *obrazek, int sirka, int vyska)
{
    if (x < 0 || x >= sirka || y < 0 || y >= vyska)
    {
        return;
    }
    pixel *p = &obrazek[y * sirka + x];

    float alpha = a0 / 255.0f;

    float r = alpha * r0 + (1.0f - alpha) * p->r;
    float g = alpha * g0 + (1.0f - alpha) * p->g;
    float b = alpha * b0 + (1.0f - alpha) * p->b;

    if (r < 0)
    {
        r = 0;
    }
    if (r > 255)
    {
        r = 255;
    }
    if (g < 0)
    {
        g = 0;
    }
    if (g > 255)
    {
        g = 255;
    }
    if (b < 0)
    {
        b = 0;
    }
    if (b > 255)
    {
        b = 255;
    }

    p->r = (byte)r;
    p->g = (byte)g;
    p->b = (byte)b;
    p->a = 255;
}

void kresli_caru(int x1, int y1, int x2, int y2, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int chyba = dx + dy;

    int x = x1;
    int y = y1;

    while (1)
    {
        nastav_pixel(x, y, r, g, b, a, obrazek, sirka, vyska);

        if (x == x2 && y == y2)
        {
            break;
        }
        int e2 = 2 * chyba;
        if (e2 >= dy)
        {
            chyba = chyba + dy;
            x = x + sx;
        }
        if (e2 <= dx)
        {
            chyba = chyba + dx;
            y = y + sy;
        }
    }
}

void kresli_obdelnik(int x, int y, int w, int h, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska)
{
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            nastav_pixel(x + i, y + j, r, g, b, a, obrazek, sirka, vyska);
        }
    }
}

void kresli_kruh(int x, int y, int p, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska)
{
    int xmin = x - p;
    int xmax = x + p;
    int ymin = y - p;
    int ymax = y + p;

    for (int i = xmin; i <= xmax; i++)
    {
        for (int j = ymin; j <= ymax; j++)
        {
            int dx = i - x;
            int dy = j - y;
            if (dx * dx + dy * dy <= p * p)
            {
                nastav_pixel(i, j, r, g, b, a, obrazek, sirka, vyska);
            }
        }
    }
}

float orientace(float ax, float ay, float bx, float by, float cx, float cy)
{
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

void kresli_trojuhelnik(int x, int y, int s, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska)
{
    float vyska_t = s * sqrtf(3.0f) / 2.0f;

    float ax = x - (2.0f / 3.0f) * vyska_t;
    float ay = y;
    float bx = x + (1.0f / 3.0f) * vyska_t;
    float by = y - s / 2.0f;
    float cx = x + (1.0f / 3.0f) * vyska_t;
    float cy = y + s / 2.0f;

    int xmin = (int)floorf(fminf(fminf(ax, bx), cx));
    int xmax = (int)ceilf(fmaxf(fmaxf(ax, bx), cx));
    int ymin = (int)floorf(fminf(fminf(ay, by), cy));
    int ymax = (int)ceilf(fmaxf(fmaxf(ay, by), cy));

    for (int i = xmin; i <= xmax; i++)
    {
        for (int j = ymin; j <= ymax; j++)
        {
            float w1 = orientace(ax, ay, bx, by, i, j);
            float w2 = orientace(bx, by, cx, cy, i, j);
            float w3 = orientace(cx, cy, ax, ay, i, j);

            int ma_stejne_znamenko = (w1 >= 0 && w2 >= 0 && w3 >= 0) || (w1 <= 0 && w2 <= 0 && w3 <= 0);
            if (ma_stejne_znamenko)
            {
                nastav_pixel(i, j, r, g, b, a, obrazek, sirka, vyska);
            }
        }
    }
}

void kresli_otoceny_obdelnik(float uhel_stupne, int cx, int cy, int w, int h, byte r, byte g, byte b, byte a, pixel *obrazek, int sirka, int vyska)
{
    float uhel = uhel_stupne * 3.1415926535f / 180.0f;

    float cos_a = cosf(uhel);
    float sin_a = sinf(uhel);

    int polovina_w = w / 2;
    int polovina_h = h / 2;

    for (int iy = -polovina_h; iy < polovina_h; iy++)
    {
        for (int ix = -polovina_w; ix < polovina_w; ix++)
        {
            float rx = ix * cos_a - iy * sin_a;
            float ry = ix * sin_a + iy * cos_a;

            int x = cx + (int)roundf(rx);
            int y = cy + (int)roundf(ry);

            nastav_pixel(x, y, r, g, b, a, obrazek, sirka, vyska);
        }
    }
}
