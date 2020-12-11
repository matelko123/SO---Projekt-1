#include <iostream>
#include <fstream>
#define fileName "psychologia-milosci.txt"

using namespace std;

void initFileStream(fstream &plik){
    plik.open(fileName);

    if(!plik || !plik.is_open()) {
        cout<<"Unable to open the file"<<endl;
        exit(1);
    }
}

int main(){
    fstream plik;
    initFileStream(plik);

    plik.close();
    return 0;
}