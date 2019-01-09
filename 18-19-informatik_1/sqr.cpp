//write a func, that returns the sqrt of a float
//180109 - softbobo
#include<iostream>
using namespace std;

float square(float num);

int main() {
    double zahl;
    cout << "Bitte Fließkommazahl eingeben" << endl;
    cin >> zahl;
    cout << "Die Quadratwurzel von " << zahl << " lautet " << square(zahl) << endl;

    return 0; 
}

float square(float num) {
    return num * num;
}