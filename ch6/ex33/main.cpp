#include <iostream>
#include <vector>
using namespace std;
using Iter = vector<int>::iterator;


void print(Iter begin, Iter end){
	if(begin!=end){
		cout<<*begin<<" ";
		print(next(begin),end);
	}
}

int main()
{
    vector<int> vec {1,2,3,4,5,6,7,8,9};
	print(vec.begin(),vec.end());
    return 0;
}