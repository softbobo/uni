//implementation of task 8.7, calculating a deer pop recursively
//softbobo 190213

#include<iostream>
#include<iomanip>
using namespace std;

int deeradd(int years, int count, int current);

int deeradd(int years, int count, int current) {
    
    if(current == years) return count;
    else {
        count = count * 3 - 10;
        if(count > 40)
            return deeradd(years, count*0.3, current + 1);
        else
            return deeradd(years, count, current + 1);        
    }
}

int main() {
    int years = 10;
    int count = 12;
    cout << setw(5) << "years" << " | " << setw(5) << "deer" << endl;
    for(int i = 1; i <= years; i++) {
        count = deeradd(i, count, 0);
        cout << setw(5) << i << " | " << setw(5) << count << endl;
    }
    return 0;
}