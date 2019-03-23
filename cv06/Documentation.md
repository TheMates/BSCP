## Cvičení 6

 **Zadání**:
Vytvořit objekt **Matice**, který má:
- dvourozměrné pole 
- konstruktory (inicial, kopír, konverzní), destruktor
- metodu pro naplnění random
- Přetíežené operátory:
	- binární + - * /
	- unární -
	- přiřazení =
	- [] pro čtení i zápis
	- << pro výpis na konzoli

 
### Soubory
 **``cv06.cpp ``**
 Obsahuje main funkci, demonstrace práce s objekty. 

-----
 **``header.h ``**
 Obsahuje deklaraci třídy **Matice**. 
Členské proměnné:
- **``double **_data``** ukazatel na pole prvků matice
- **``unsigned int _rows, cols``** dimenze matice

Privátní metody:
- **``scalarOperation()``** - pro operaci matice se skalárem, využito pro všechny operátory + - * / kvůli zamezení duplicity kódu
-**`` matrixOperation()``** pro operaci mezi dvěma maticemi, stejný důvod jako výše.

Poté obsahuje deklaraci všech povinných metod.

---
**``myclasses.cpp``**
Definice funkcí třídy.

Konstruktory a destruktory jsou docela intuitivní. Defaultní konstruktor ``Matice()`` nastaví ukazatel ``_data``na ``NULL``.

- Unární operátor - vrací novou matici nejdříve vytvořenou z původní s opačnými čísly.

- operátor ``<<`` vypíše na konzoli cyklem ``cout<<_data[r][c]``

- všechny binární operátory + - * / s parametry **``(const Matice& first, const Matice& second)``** odkazují na privátní metodu **``matrixOperation()``**, která má jako jeden z parametrů lambda funkci, která specifikuje operaci pro aktuální operátor (+ - * /). Metoda **``matrixOperation()``** **throws** *"Dimensions mismatch!"*  pokud jsou parametry dvě matice s nestejnými rozměry.

- operátor přiřazení **``Matice& Matice::operator=(const Matice& src)``** nejdříve zkontroluje, jestli data v cílovém objektu ukazují na ``NULL``, pokud ne, provede stejnou operaci jako kopírovací konstruktor. Pokud ano, data se nejdříve z cílového objektu smažou.

- **``void scalarOperation(double scalar, double(* operation)(double, double))``**
Privátní metoda, která provede operaci nad všemi prvky matice se skalární hodnotou, která je poslaná parametrem. Operace je zadaná lambda funkcí, jako druh parametr funkce (operace + - * /).

-**``static Matice& matrixOperation(const Matice& loperand, const Matice& roperand, double(* operation)(double, double))``**
Privátní metoda, která zajišťuje podobnou funkcionalitu jako předchozí funkce. Tuto metodu volají všechny veřejné operátory + - * /. Předají levý a pravý operand a lambda funkci, která zajišťuje + - * /.  
Nejdříve se v metodě rozhodne, zda není jeden z operandů skalár, potom odkáže na ``scalarOperation()`` a vrátí výsledek.
Pokud žádný z operandů není skalár, zkontroluje se velikost obou matic, pokud nejsou shodné **throws** *"Dimensions mismatch!"*
Poté se provede oprace mezi prvky matice + - * /. *
(Jde o operaci mezi prvkami matice, násobení a dělení mezi maticemi správně probíhá jinak, ale to jsem neimplementoval)*


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE0NTA2MDU0MTJdfQ==
-->