

using namespace std;
#include<iostream>

int fakultaet(int num);

int main() {
    int num;
    cout << "Bitte Zahl eingeben: " << endl;
    cin >> num;
    cout << "Das Ergebnis lautet: " << calculon(num) << endl;
    return 0;
}

int fakultaet(int num_2) {
    if(num_2 == 0)
        return 1;
    for(int i = num_2 - 1; i >= 1; i--)
        num_2 *= i;
    return num_2;
}
float calculon(int num_1) {
    float sum = -1;
    for(int i = 2; i < num_1 - 1; i+2) {//???
        sum += (1/fakultaet(i));
        sum -= (1/fakultaet(i+1));
    }
    sum *= 
    sum *= (1/fakultaet(num_1));
    return sum;

}