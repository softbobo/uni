//Game that let's program guess umber unser imagines
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    int a, b;
    char sign;
    int c=(b-a)/2;

    cout << "Please enter min value: " << endl; 
    cin  >> a;
    cout << "Please enter max value: " << endl;
    cin >> b;

    cout << "Pick one Number within the given range." << endl;
    cout << "But keep it for yourself!" << endl;


    cout << "Is the number you chose " << c << "?" << endl;
    cout << "Please enter, if the number is smaller, bigger or even to the guessed number.";
    cin >> sign;
     for (char sign != '=')
     {
      if (sign = '<')
      c=c/2
      
      else if (sign = '>')
      c=c++;
      
     }


    return 0;
}

