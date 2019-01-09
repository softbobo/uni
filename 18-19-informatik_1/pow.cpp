
#include<iostream>
using namespace std;

float power (float num, float exp) {
    float sum = 1;
    for(int i = 1; i <= exp; i++) {
        sum *= num;
    }
    return sum;
 }

int main() {
    float num = 0, exp = 0;
    cout << "Bitte Zahl eingeben: " << endl;
    cin >> num;
    cout << "Bitte Exponenten eingeben: " << endl;
    cin >> exp;
    cout << "Die Potenz lautet: " << power(num, exp) << endl;
    return 0;
}