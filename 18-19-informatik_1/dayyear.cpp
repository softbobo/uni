#include<iostream>
using namespace std;

int main()
{
int d,m,y,sum=0;
cout<<"Bitte Tag, Monat und Jahr getrennt voneinander eingeben."<<endl;
cin>>d>>m>>y;

if(y%4==0)
  sum++;
else sum=0;
sum+=d;
switch(m)
 {
 case 1: break;
 case 2: {sum+=31;}break;
 case 3: {sum+=59;}break;
 case 4: {sum+=90;}break;
 case 5: {sum+=120;}break;
 case 6: {sum+=151;}break;
 case 7: {sum+=181;}break;
 case 8: {sum+=212;}break;
 case 9: {sum+=243;}break;
 case 10: {sum+=273;}break;
 case 11: {sum+=304;}break;
 case 12: {sum+=334;}break;
 }
cout<<"Das Jahr ist "<<sum<<" Tage alt"<<endl;
return 0;
}
