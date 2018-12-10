#include<iostream>
using namespace std;

int main()
{
int time, h, m;
cout<<"Bitte Uhrzeit in der Form hhmm eingeben"<<endl;
cin>>time;
h=(time/100)+1;
 if(12<h<=24)
    h-=12; 
m=time%100;
cout<<"Stunden: "<<h<<" Minuten: "<<m<<endl;
switch(m)
{
  case 15: 
  {cout<<"Es ist viertel "<<h<<'.'<<endl;} break;
  case 30:
  {cout<<"Es ist halb "<<h<<'.'<<endl;} break;
  case 45:
  {cout<<"Es ist dreiviertel "<<h<<'.'<<endl;} break;
  case 00:
  {cout<<"Es ist um "<<h<<'.'<<endl;}break;
  default:
  {cout<<"Bitte nur Werte auf die Viertelstunde genau eingeben."<<endl;}break;
}
return 0;
}
