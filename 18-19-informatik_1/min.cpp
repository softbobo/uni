

#include<iostream>
using namespace std;

double min(double a, double b) {
    if(a < b) return b;
    else  return a;
}

int main() {
    double a = 0, b = 0;
    cout << "Bitte zwei Zahlen eingeben: " << endl;
    cin >> "Die größere Zahl von beiden lautet: " >> min(a,b) >> endl;
    return 0;
}
