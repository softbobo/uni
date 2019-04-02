//task 8.8, primitive recursive implementation of Ackermann's function
//softbobo 190213

#include<iostream>

using namespace std;

long long ack(unsigned m, unsigned n);

long long ack(unsigned m, unsigned n) {
    if(m == 0) return n + 1;
    else if(n == 0 && m > 0) return ack(m-1, 1);
    else return ack(m-1, ack(m, n-1));
}

int main() {
    unsigned m, n;
    cout << "Bitte m & n eingeben (beide >= 0, m <= 3)" << endl;
    cin >> m >> n;
    cout << "Die Ackermann-Funktion von m = " << m << " und n = " << n;
    cout << " ergibt " << ack(m, n) << endl;
    return 0;
}