//program that takes a num x and gives out its value

#include <iostream>
using namespace std;

int main(long double x)
{
    cout<<"Please enter a number x"<<endl;
    cin>>x;
    if(x<0)
    {					//convert x to pos float, if it's smaller than 0
    x*=-1;
    cout<<x<<endl;
    }
    else 
    cout<<x<<endl;
    return 0;
}
