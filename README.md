-- Vytváření TGA obrazců --

Tento program načítá textové příkazy ze standardního vstupu a podle nich vykresluje tvary do TGA obrázku.

Pokyny pro zápis do konzole
- Pro inicializaci programu zapomoci Makefile:
  - make

- Makefile provede kompilaci pomocí příkazu:
  - gcc main.c tga.c kresleni.c prikazy.c -o program -lm

- Zadání parametrů pro spuštění programu:
  - ./program --width <šířka> --height <výška> --output <soubor.tga>

Poté program bude čekat na jednotlivé zadání pro obrazce.

Seznam obrazců a jejich parametrů:
- Čára:
  - line pozice x1, pozice y1, pozice x2, pozice y2, červená, zelená, modrá, průhlednost
- Obdelník:
  - rectangle pozice x, pozice y, šířka, výška, červená, zelená, modrá, průhlednost
- Kruh:
  - circle pozice x, pozice y, poloměr p, červená, zelená, modrá, průhlednost
- Trojúhelník:
  - triangle pozice x, pozice y, délka strany s, červená, zelená, modrá, průhlednost
- Otočený obdelník:
  - rotated-rectangle úhel, pozice x, pozice y, šířka, výška, červená, zelená, modrá, průhlednost

Funkce:
- save
  - Uloží obrazce do souboru s tga příponou a program načítá další hodnoty.
- exit
  - Uloží obrazce do souboru s tga příponou a program se ukončí.
