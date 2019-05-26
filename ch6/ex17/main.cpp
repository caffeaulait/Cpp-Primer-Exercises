#include <iostream>
#include <string>
using namespace std;


bool hasUpper(const string &str){
	for(auto c : str)//pass by value
		if(isupper(c))
			return true;
	return false;
}


const string& makeLower(string &str){
	for(auto &c : str) //pass by reference
		if(isupper(c))
			c=tolower(c);
	return str;
}
int main()
{
    string str("HELLO");
	cout<<boolalpha<<hasUpper(str)<<endl;
	cout<<makeLower(str)<<endl;
    return 0;
}