#include <iostream>
using namespace std;

int main()
{
int a,b;
cout<<"Bitte Variablen a und b eingeben."<<endl;
cin>>a>>b;
if(a%2==0||b%2==0)
  cout<<"Mindestens eine der beiden Zahlen ist restlos durch zwei teilbar"<<endl;
else
  cout<<"Keiner der beiden eingegebenen Werte ist gerade"<<endl;
return 0;
}
