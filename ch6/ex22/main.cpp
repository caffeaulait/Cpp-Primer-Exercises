#include <iostream>
using namespace std;

void swap(const int*& lhs, const int*& rhs){
	auto temp = lhs;
	lhs = rhs;
	rhs= temp;
}

int main()
{
	const int i = 50, j =60;
	auto lhs = &i, rhs = &j;
	swap(lhs,rhs);
	cout<<*lhs<<" "<<*rhs<<endl;
    return 0;
}