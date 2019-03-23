## Cvičení 4

 **Zadání**:
Udělat objekt **Pole**, který má:
- jednorozměrné pole, typ int
- konstruktor 1 parametr = velikost
- konstruktor 2 par - velikost, hodnota všech prvků
- konverzní konstr - par char* - konverze z char do int
- kopírovací konstr
- metoda naplnění random
- metoda sčítání prvků 2 polí, binární, 1 par
- metoda tisk
- destruktor

Dále:
- friend sčítání 2 polí - 3 par, A, B, výsledek C
 
### Soubory
 **``maincv04.cpp ``**
 Obsahuje main funkci, demonstrace konstruktorů a práce s objekty. Dynamická i statická inicializace.

-----
 **``header.h ``**
 Obsahuje deklaraci třídy **Pole**. 
 Kromě zadaných funkcí ještě obsahuje metody
 -  ``getLength()`` - vrátí velikost pole
 -  ``oeprator[](unsigned int index) `` - vrátí hodnotu na pozici index

Metoda pro sčítání dvou prvků je ``add(Pole &second) ``.

---
**``myclasses.cpp``**
Definice funkcí třídy.
Konstruktory a destruktory jsou docela intuitivní.
- ``fillRand() `` naplní pole náhodnými hodnotami od 0 do 100.
- ``print()`` vypíše na konzoli cyklem cout<<pole[i]
- ``add(Pole &second)`` přičte k poli, u kterého se funkce volá hodnoty prvků druhého pole. Pokud nejsou velikosti polí stejné **throws** *"Size mismatch!"*.
- ``friend add(Pole& A, Pole& B, Pole& C)`` - pokud nejsou **A**, **B** a **C** stejně velké **throws** "Size mismatch!". Jinak do pole **C** zapíše součet prvků **A+B**.
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE0NTM5MjM3MzhdfQ==
-->