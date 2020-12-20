#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fileHelper.h"
#define FileName "psychologia-milosci.txt"
#define DoneFileName "psychologia-milosci_done.txt"

using namespace std;

/* TODO
 ✅ Stworzyć funkcje do sprawdzania plikow a gdy plik nie istnieje to go tworzy
 ✅ Poprawiać stringi aby nie miały znakow specjalnych
 * Dodać więcej znakow specjalnych
 * Poprawić MAKEFILE
 * Sortowanie
 */

void countSort(string tab[], int rozm, int exp){
    string *out = new string[rozm];
    int i = 0;
    int count[26] = {0};

    for (int i = 0; i < rozm; i++){
        string tmp = tab[i];
        char znak = (exp < tmp.length())? tmp[exp]: 'A';
        count[znak-65]++;
    }

    for (int i = 1; i < 26; i++)
        count[i] += count[i-1];


    for (int i = rozm - 1; i >= 0; i--) {
        string tmp = tab[i];
        char znak = (exp < tmp.length())? tmp[exp]: 'A';
        int idx = count[znak-65];
        out[idx-1] = tab[i];
        count[znak-65]--;
    }

    for (int i = 0; i < rozm; i++)
        tab[i] = out[i];
}

void saveData(fstream &plik, string tab[], int rozm){
    if(!plik) throwError(1, "Corrupted file");
    plik.seekg(0);

    for (int i = 0; i < rozm; i++)
        plik<<tab[i]<<endl;
}

void radixSort(string tab[], int rozm){
    int m = getMaxLength(tab, rozm);

    for (int i = 0; i < m; i++)
    {
        countSort(tab, rozm, i);
    }
}

/* ------------- PRZEBIEG ------------- *\
 * 1. Załadowanie słow z pliku do tablicy
 * 2. Sortowanie radix sortem
 * 3. Zapis danych do pliku
 */

int main(){
    fstream plik;
    initFileStream(plik, FileName);
    
    unsigned int rozm = getCountOfWords(plik);

    cout<<"Allocating memory for "<<rozm<<" strings.."<<endl;
    string *tab = new string[rozm];
    if(tab==NULL) throwError(2, "Allocation error");
    
    loadDataFromFile(plik, tab, rozm);

    fstream done;
    initFileStream(done, DoneFileName);
    radixSort(tab, rozm);
    saveData(done, tab, rozm);

    plik.close();
    return 0;
}