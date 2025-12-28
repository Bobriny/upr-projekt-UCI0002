-- Vytváření TGA obrazců --

Tento program načítá textové příkazy ze standardního vstupu a podle nich vykresluje tvary do TGA obrázku.

Pokyny pro zápis do konzole
- Pro inicializaci programu zapomoci Makefile:
  - make

- Makefile provede kompilaci pomocí příkazu:
  - gcc main.c tga.c kresleni.c prikazy.c -o program -lm

- Zadání parametrů pro spuštění programu:
  - ./program --width <šířka> --height <výška> --output <soubor.tga>

Pokud neexistuje soubor s .tga příponou, vytvoří jej.
Poté program bude čekat na jednotlivé zadání pro obrazce.

Seznam obrazců a jejich parametrů:
- Čára:
  - line pozice x1, pozice y1, pozice x2, pozice y2, červená, zelená, modrá, průhlednost
    příklad:
  - line 10,10,100,100,255,0,0,255 - Červená čára z pozice (10,10) do pozice (100,100).
- Obdelník:
  - rectangle pozice x, pozice y, šířka, výška, červená, zelená, modrá, průhlednost
    příklad:
  - rectangle 150,150,40,150,0,250,0,250 - Zelený obdelník s levým horním krajem na pozici (150,150) o šířce 40 a výšce 150.
- Kruh:
  - circle pozice x, pozice y, poloměr p, červená, zelená, modrá, průhlednost
    příklad:
  - circle 250,250,25,0,0,250,250 - Modrý kruh se středem v bodě (250,250) s poloměrem 25.
- Trojúhelník:
  - triangle pozice x, pozice y, délka strany s, červená, zelená, modrá, průhlednost
    příklad:
  - triangle 300,300,70,250,250,0,250 - Žlutý rovnostranný trojúhelník se středem v bodě (300,300) s délkou strany 70.
- Otočený obdelník:
  - rotated-rectangle úhel, pozice x, pozice y, šířka, výška, červená, zelená, modrá, průhlednost
    příklad:
  - rotated-rectangle 70,120,120,120,60,250,250,250,250 - Bílý obdelník pootočený o 70 stupňů se středem v bodě (120,120) o šířce 120 a výšce 60.

Funkce:
- save
  - Uloží obrazce do souboru s tga příponou a program čeká na zadání dalších pokynů.
- exit
  - Uloží obrazce do souboru s tga příponou a program se ukončí.
