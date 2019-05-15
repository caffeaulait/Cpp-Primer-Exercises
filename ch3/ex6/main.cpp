#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str("a simple string");
	for (auto &c:str)
		c = 'X';
	cout<<str<<endl;
    return 0;
}