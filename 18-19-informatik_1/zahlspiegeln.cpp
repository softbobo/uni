//task 7.9, returns mirrored value of an int as int
//softbobo 180109

using namespace std;
#include<iostream>

int mirror(int num);

int main() {
    int num = 0;
    cout << "Bitte Zahl eingeben: " << endl;
    cin >> num; 
    cout << "Der Spiegelwert lautet: " << mirror(num) << endl;
    return 0;
}

int mirror(int num) {
    int result = 0;
    while(num > 0) {
        result += num % 10;
        cout << "Result: " << result << endl;
        num /= 10;
        cout << "Number: " << num << endl;
        result *= 10;
    }
    return result / 10;
}