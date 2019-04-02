//simple implementation of the euclidean algo
//softbobo 190213
#include<iostream>
using namespace std;

int euclid(int a, int b);

int euclid(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    if(a == b) return a;

    if(a > b) return euclid(a - b, b);
    else return euclid(a, b-a);
}

int main() {
    int a, b;
    cout << "Please enter two Numbers." << endl;
    cin >> a >> b;
    cout << euclid(a,b) << endl;
    return 0;
}