//returns all numbers between 1 and 100, except those which are dividable or multiples of 7
//task 4.11

#include<iostream>

using namespace std;

int main(){
    //main does everything
    int x;
    for(x = 1; x <= 100; x++){
        //all numbs 1-100
        if(!(x % 7 == 0) && !(x % 10 == 7) && !(x / 10 == 7)){
            cout << x << " "; 
        }
    }
    cout << endl;
    return 0;
}
