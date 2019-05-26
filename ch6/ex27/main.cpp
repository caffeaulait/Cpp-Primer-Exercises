#include <iostream>
#include <initializer_list>


int sum(const std::initializer_list<int> list){
	int sum =0;
	for(auto i : list)
		sum+=i;
	return sum;
}


int main()
{
	std::cout << sum({1,2,3,4,5});
    return 0;
}