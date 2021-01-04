#include "helper.h"

void throwError(int status=1, string msg="Something went wrong"){
    cout<<msg<<endl;
    exit(status);
}

Projekt::Projekt() 
{
    cout << "Hello!!" << endl;

    this->in.open(FileName, ios::in);
    if (!this->in.good()) throwError(1, "Unable to open file.");
    
    this->out.open(DoneFileName, ios::out | ios::trunc);
    if (!this->out.good()) throwError(1, "Unable to open file.");
}
Projekt::~Projekt(){
    this->in.close();
    this->out.close();
    cout << "Bye!" <<endl;
}

// Data load / save
void Projekt::loadDataFromFile(){
    cout << "Loading strings from file..." << endl;

    if(!this->in) throwError(1, "Corrupted file.");

    string tmp;
    while(!this->in.eof()){
        this->in >> tmp;
        prepareString(tmp);
        if(tmp.length() > 0) this->tab.push_back(tmp);
    }
}
void Projekt::savaDataToFile(){
    cout << "Saving strings to file..." << endl;

    if(!this->out || !this->out.good()) throwError(1, "Corrupted file");

    for(vector<string>::iterator it = this->tab.begin(); it != this->tab.end(); it++){
        this->out << *it << endl;
    }
}

// Prepare string
void Projekt::trim(string &str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
        return;
    
    size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last - first + 1));
}
bool Projekt::isCharAlpha(const char &c){
    if(c >= 'A' && c <= 'Z') return true;
    else return false;
}
void Projekt::prepareString(string &str){
    trim(str);                                                  // Trim string
    transform(str.begin(), str.end(), str.begin(), ::toupper);   // String to upper case

    int i = 0;
    while(!isCharAlpha(str[i]) && i<str.length()) i++;

    int j = i;
    while(isCharAlpha(str[j]) && j<str.length()) j++;

    str = str.substr(i, j-i);
}
int Projekt::getMaxLength(){
    int maxi=0;
    for(vector<string>::iterator it = this->tab.begin(); it != this->tab.end(); it++)
        if(it->length() > maxi) maxi = it->length();

    return maxi;
}

// Sort
void Projekt::countSort(const int exp){
    const int rozm = this->tab.size();
    string *out = new string[rozm];
    int count[26] = {0};
    int i = 0;

    for (int i = 0; i < rozm; i++){
        string tmp = this->tab[i];
        char znak = (exp < tmp.length())? tmp[exp]: 'A';
        count[znak-65]++;
    }

    for (int i = 1; i < 26; i++)
        count[i] += count[i-1];

    for (int i = rozm - 1; i >= 0; i--) {
        string tmp = this->tab[i];
        char znak = (exp < tmp.length())? tmp[exp]: 'A';
        int idx = count[znak-65];
        out[idx-1] = this->tab[i];
        count[znak-65]--;
    }

    for (int i = 0; i < rozm; i++)
        this->tab[i] = out[i];
}
void Projekt::radixSort() {
    cout << "Sorting..." << endl;
    if(!this->out || !this->out.good()) throwError(1, "Corrupted file");

    int m = getMaxLength();

    for(int i = 0; i < m; i++)
        countSort(i);

    cout<<"Done!!"<<endl;
}