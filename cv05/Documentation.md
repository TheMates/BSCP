## Cvičení 5

 **Zadání**:
 Vytvořit abstraktní třídu **Tvar** - deklaruje rozhranní práce s obkejty
 - čistě virtuální metoda pro tisk, obvod, obsah
Tvar obsahuje:
- dynamické pole rozměrů
- konstruktor a destruktor

Vytvořit odvozené třídy **Kruh, Trojuhelnik, Obdelnik, Barevny_Obdelnik**
- definují funkce pro tisk, obvod obsah
- konstruktory pro definici rozměrů
- **Barevny_Obdelnik** dědí z **Obdelnik**, rozšiřuje jej barvou

Dále:
- funkci pro řazení objektů podle obvodu nebo obsahu
 
#### Soubory
 **``cv05.cpp ``**
 Obsahuje main funkci. Vytvoří se ukazatel na pole ``Tvar[10]`` a pak se naplní různými tvary. Je ukázána funkcionalita funkce pro tisk.
 Potom se volá nad polem funkce pro řazení a seřazené objekty se vypíší znovu.

-----
 **``header.h ``**
 Obsahuje deklaraci všech tříd.
 **Tvar**: 
 Obsahuje ukazatel na pole typu ``float``, taky ``int``velikost 
a také dvě privátní metody
 -  ``printPrivate()`` - vrátí string, který obsahuje vypsaný obvod a obsah, jinak by se ten samý řádek dělal v každé implementaci ``print`` v odvozených třídách zvlášť.
 -  ``friend void swap(Tvar &a, Tvar &b)`` - funkce pro prohození dvou objektů - použito při řazení.

Konstruktor přijímá pouze velikost pro alokaci privátního pole.

Odvozené třídy mají potom vlastní konstruktory podle počtu parametrů, které volají bázový konstruktor.

---
**``myclasses.cpp``**
Definice funkcí třídy.
Konstruktory a destruktory jsou docela intuitivní. Funkce pro výpočet obvodu a obsahu jsou jen matematika.

- **``void sortByParameter(Tvar** col, unsigned size, bool byObvod, bool ascending)``**
Funkce, která seřadí objekty v poli. **``Tvar **col``** ukazatel na pole, které zabaluje objekty Tvarů. **``size``** je velikost daného pole. Bool flags jsou pochopitelné.
Uvnitř funkce je cyklus, který najde nový nejnižší prvek (**``getNext()``**) a potom aktuální a nový prohodí pomocí friend funkce **``swap()``**

- **``int getNext(Tvar **col, unsigned int startIdx, unsigned int size, bool byObvod, bool ascending)``**
Přijímá stejné parametry jako výše zmíněná funkce, navíc s **``startIdx``** což je pozice v  **``col``** odkud hledat další prvek. Podle bool parametrů se nadje další menší nebo větší prvek než zadaný **``startIdx``** buď podle obvodu nebo podle obsahu. Funkce vrátí jeho index.

- **``void swap(Tvar& a, Tvar& b)``**  protože ``std::swap()`` není definovaná pro třídu Tvar tak je implementována tak, že jednoduše prohodí nejdřív vnitřní pole rozměrů a pak parametr ``_size``pomocí funkce ``std::swap()``
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTkzMjAyMzkzMF19
-->