#include <iostream>
using namespace std;

int larger(int i, const int* const ip){
	return(i>*ip)?i:*ip;
}

int main()
{
    int c = 6;
	cout<<larger(7,&c)<<endl;
    return 0;
}