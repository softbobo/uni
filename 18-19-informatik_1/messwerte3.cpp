//takes 20 args and populates array of 20 with it
//after that calcs mean, checks for different parameters
//task 5.11

//INCOMPLETE

#include<iostream>
using namespace std;

double meancalc(double* args);

int main(void){
    //main does everything
    int num = 20;
    double arr[num];                                            //array takes args
    int i;
    for(i = 0; i <= 19; i++){                               //populates array
        cout << "Bitte Messwert " << i+1 << "eingeben";
        cin >> arr[i];
    }
    double mean = meancalc(arr);




}

double meancalc(double args[20]){
    //calculates mean of all args in arr

}