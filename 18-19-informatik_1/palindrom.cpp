//checks, if charstring is an palindrome
//task 5.2

#include<iostream>
using namespace std;

int main(void){

    char arr[31];                   //max chars 30 + terminating zero
    cout << "Please enter charstring: " << endl;
    cin >> arr;
    int i;
    int j = 0;
    while(arr[j] != '\0')
        j++;
    j--;

    cout << "strlen: " << j <<endl;

    bool answer = true;
    for(i=0; i < j && answer; i++, j--){
        if(arr[i] == arr[j]){
            answer = true;  
        }
        else
            answer = false;   
    }
    if(answer == true){
        cout << arr << " ist ein Palindrom!" << endl;
    }
    else if(answer == false)
        cout << arr << " ist kein Palindrom!" << endl;
    
    return 0;

}