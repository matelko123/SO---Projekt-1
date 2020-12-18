#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include "fileHelper.h"
#define orgFileName "psychologia-milosci.txt"
#define endFileName "psychologia-milosci_done.txt"

using namespace std;

/* TODO
 ✅ Stworzyć funkcje do sprawdzania plikow a gdy plik nie istnieje to go tworzy
 ✅ Poprawiać stringi aby nie miały znakow specjalnych
 ✅ Dodać więcej znakow specjalnych
 * Poprawić MAKEFILE
 * Sortowanie
 */

int main(){
    fstream org;
    initFileStream(org, orgFileName);

    fstream plik;
    remove(endFileName);
    initFileStream(plik, endFileName);

    prepareFile(org, plik);

    org.close();
    plik.close();
    return 0;
}