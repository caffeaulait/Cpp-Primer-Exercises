#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void swap(int* const lhs, int* const rhs){
	auto temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void swap(int& lhs, int& rhs){
	auto temp = lhs;
	lhs=rhs;
	rhs= temp;
}

int main()
{
    int lhs, rhs;
	cout<<"Please Enter two numbers:\n";
	cin>>lhs>>rhs;
	swap(&lhs,&rhs);
	cout<<lhs<<" "<<rhs<<endl; 
	swap(lhs,rhs);
	cout<<lhs<<" "<<rhs<<endl; 
    return 0;
}