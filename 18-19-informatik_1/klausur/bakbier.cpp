//implementation for task 4.16
//softbobo 190211

#include<iostream>
#include<iomanip>
using namespace std;

float calc_bac(float m, float e, int v);
void bph(float m, float e, int v);

int main(){
    float m, e;                         //mass in pers in kgs and percentage of alcohol in drink
    int v;                              //volume of drink in ml
    cout << "please enter mass of person in kgs " << endl;
    cin >> m;
    cout << "please enter alcohol percentage in drink " << endl;
    cin >> e;
    cout << "please enter volume of drink in mls " << endl;
    cin >> v;

    cout << "säufst du 10 Bier in 10 Stunden, sieht dein Blutalkoholwert so aus: " << endl;
    bph(m, e, v);
    
    return 0;
}

float calc_bac(float m, float e, int v) {
    float a = v * (e/100) * 0.8;
    return a / (m * 0.62);
}

void bph(float m, float e, int v) {
    cout << setw(5) << "Beers" << " | " << setw(5) << "alc" << endl;
    for(int i = 1; i < 11; i++) {
        cout << setw(5) << i << " | " << setw(5) << calc_bac(m, e, v*i) - (i*0.15) << endl;
    }
}