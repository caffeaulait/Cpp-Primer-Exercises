#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
	cin>>str1>>str2;
	if(str1==str2)
		cout<<"the two strings are equal"<<endl;
	else
		cout<<"the larger string is "<<((str1>str2)?str1:str2)<<endl;
	
	if(str1.size()==str2.size())
		cout<<"the two strings have the same length."<<endl;
	else
		cout<<"the longer string is "<<((str1.size()>str2.size())?str1:str2);
    return 0;
}