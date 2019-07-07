#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::cout << "Hello, World" << std::endl;

    return 0;
}

bool find(vector<int>::iterator beg, vector<int>::iterator end, int value){
	for(auto iter = beg; iter !=end; ++iter){
		if(*iter==value)
			return true;
	}
	return false;
}

vector<int>::iterator find2(vector<int>::iterator beg, vector<int>::iterator end, int value){
	for(auto iter =beg; iter!=end;++iter){
		if(*iter==value)
			return iter;
	}
	return end;
}