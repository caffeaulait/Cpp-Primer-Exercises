#include <iostream>
#include <string>
using namespace std;

int main()
{
    string largeStr;
	string str;
	while (cin>>str){
		if(largeStr.empty())
			largeStr+=str;
		else
			largeStr+=" "+str;
	}
	
	cout<<"the concatenated string is "<<largeStr<<endl;
    return 0;
}