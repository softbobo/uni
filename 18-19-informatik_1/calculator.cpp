#include<iostream>

using namespace std;

int main()
{
float operand1, operand2;
char op;
cout<<"Bitte die beiden Operanden eingeben."<<endl;
cin>>operand1>>operand2;
cout<<"Bitte die gewünschte Rechenoperation als Zeichen (+,-,*,/) eingeben."<<endl;
cin>>op;
float result;
  switch(op)
  {
  case '+':
    {result=operand1*operand2;
    }break;
  case '-':
    {result=operand1-operand2;
    }break;
  case '*':
    {result=operand1*operand2;
    }break;
  case '/':
    {if(operand2!=0)
       result=operand1/operand2;
     else
       cout<<"Teilen durch null ist nicht gestattet"<<endl;
    }break;
  default:
    cout<<"Bitte gültiges Rechenzeichen eingeben!"<<endl;
  }
cout<<"Das Ergebnis lautet: "<<result<<'.'<<endl;
}
