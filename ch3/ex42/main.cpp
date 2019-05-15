#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> ivec {0,1,2,3,4,5,6,7,8,9};
	
	int arr[10];
	
	for(int *i=begin(arr);i!=end(arr);++i)
		*i = ivec[i-begin(arr)];
	
	for(auto i : arr)
		cout<<i<<" ";
	cout<<endl;
    return 0;
}