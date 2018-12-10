//simple i/o code that tells you to get well soon
//should you be sick

#include <iostream>
//#include <string>
using namespace std;

int main()
{
	char answer;
	cout << "Are you ill? Pleaser answer y for yes or n for no?" << endl;
	cin >> answer;
	if(answer=='y')
	cout << "Get well soon, kleiner Pomoshnik!!!!" << endl;
	if(answer=='n')
	cout << "Nothing to loose here!" << endl;
	return 0;
}
