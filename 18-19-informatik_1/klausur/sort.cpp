//trying out the sort() function 

#include<iostream>
#include<algorithm>

using namespace std;
struct car{
    char make[50];
    int year;
};

bool agesort(const car &a, const car &b);

int main() {
    car* list = new car[5];
    
    for(int i = 0; i < 5; i++) {
        cout << "Enter car brand and year for car number " << i << endl;
        cin >> list[i].make >> list[i].year;
    }
    sort(list, list+5, agesort);
    for(int i = 0; i < 5; i++) {
        cout << "Car No. " << i << " year made: " << list[i].year;
        cout << " brand " << list[i].make << endl;
    }
    delete [] list;
    return 0;
}

bool agesort(const car &a, const car &b) {
    return a.year < b.year;
}