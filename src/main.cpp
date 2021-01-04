#include <iostream>
#include <fstream>
#include <string>
#include "./helper/helper.h"

using namespace std;

int main(){
    Projekt p1;

    p1.loadDataFromFile();
    p1.radixSort();
    p1.savaDataToFile();

    return 0;
}