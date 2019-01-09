

using namespace std;
#include<iostream>

int fakultaet(int num);

int main() {
    int num;
    cout << "Bitte Zahl eingeben: " << endl;
    cin >> num;
    cout << "Die Fakultaet von " << num << " lautet: " << fakultaet(num) << endl;
    return 0;
}

int fakultaet(int num) {
    if(num == 0)
        return 1;
    for(int i = num - 1; i >= 1; i--)
        num *= i;
    return num;
}