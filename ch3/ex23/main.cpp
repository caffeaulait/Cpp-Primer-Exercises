#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> ivec(10,1);
	for(auto it = ivec.begin();it!=ivec.end();++it)
		*it *=2;
		
	for(auto value:ivec)
		cout<<value<<" ";
	
	cout<<endl;
    return 0;
}