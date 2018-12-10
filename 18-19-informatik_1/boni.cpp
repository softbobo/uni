//task 3.7, 14.11.2018
//simple calculations of bonus salary

#include<iostream>

using namespace std;

int main()
{
  float salary, years;
  cout<<"Bitte geben Sie ihr monatliches Gehalt ein"<<endl;
  cin>>salary;
  cout<<"Bitte geben Sie die Jahre, die Sie bereits für den Betrieb arbeiten,an"<<endl;
  cin>>years;
     if(5<=years<10)
       {
       cout<<"Ihr monatliches Gehalt beträgt: "<< salary*1.03<<" Euro."<<endl;
       }
     else if(10<=years<15)
       {
       cout<<"Ihr monatliches Gehalt beträgt: "<< salary*1.08<<" Euro."<<endl;
       }
     else if(15<=years)
       {
       cout<<"Ihr monatliches Gehalt beträgt: "<<salary*1.18<<" Euro."<<endl;
       }
     else
       {
       cout<<"Ihr monatliches Gehalt beträgt: "<< salary <<"  Euro."<<endl;
       }
  return 0;
}
