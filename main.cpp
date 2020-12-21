#include <iostream>
#include <fstream>
#include <string>
#include "fileHelper.h"
#define FileName "_text.txt"
#define DoneFileName "_done.txt"

using namespace std;

/* TODO
 * Poprawić MAKEFILE, dodać cpp 11?
 * Poprawić funkcje i stylystyke
 */

void countSort(string tab[], const unsigned int rozm, const int exp){
    string *out = new string[rozm];
    int count[26] = {0};
    int i = 0;

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

void radixSort(string tab[], const unsigned int rozm){
    int m = getMaxLength(tab, rozm);
    for (int i = 0; i < m; i++)
        countSort(tab, rozm, i);
}

int main(){
    fstream plik;
    plik.open(FileName, ios::in);
    if (!plik.good()) throwError(1, "Unable to open file.");

    unsigned int rozm = getCountOfWords(plik);
    cout<<"Allocating memory for "<<rozm<<" strings.."<<endl;

    string *tab = new string[rozm];
    if (tab == NULL) throwError(2, "Allocation error");

    loadDataFromFile(plik, tab, rozm);

    fstream done;
    done.open(DoneFileName, ios::out | ios::trunc);
    if (!done.good()) throwError(1, DoneFileName);

    radixSort(tab, rozm);
    saveData(done, tab, rozm);

    plik.close();
    return 0;
}