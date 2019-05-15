#include <iostream>
#include <string>
using namespace std;

int main()
{
	//read one line at a time
    string input;
	while(getline(cin,input))
		cout<<input<<endl;
	//read one word at a time
//	string word;
//	while(cin>>word)
//		cout<<word<<endl;
    return 0;
}