#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> v = {1,2,3,4,5,6};
    cout<<count(v.begin(),v.end(),5)<<"\n";
    
    list<string> l = {"h", "hh" , "hhh", "hh"};
    cout<<count(l.begin(),l.end(),"hh")<<endl;
	return 0;
}
