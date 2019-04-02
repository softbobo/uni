/*implementation of the mccarthy function, task from test exam*/
//softbobo 190219

/* works, puts out 91 for all values 1 <= n <= 101 */

#include<iostream>
#include<iomanip>

using namespace std;

int mccarthy(int n);

int main() {
    cout << setw(3) << "n" << " | " << setw(6) << "result" << endl;
    for(int i = 1; i <= 101; i++) {
        cout << setw(3) << i << " | " << setw(6) << mccarthy(i) << endl;
    }
    return 0;
}

int mccarthy(int n) {
    if(n > 100) return n-10;
    else return mccarthy(mccarthy(n+11));
}