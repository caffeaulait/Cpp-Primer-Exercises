#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(auto prev = lst.before_begin(),curr=lst.begin();curr!=lst.end();)
		if(*curr%2)
			curr = lst.erase_after(prev);
		else
			prev = curr++;
	
	for(auto i : lst )
		cout<<i<<" ";
	cout<<endl;
	
	return 0;
}