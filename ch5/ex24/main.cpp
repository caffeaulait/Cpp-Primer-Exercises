#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a ,b;
	std::cin>>a>>b;
	
	if(b==0) throw runtime_error("division by 0");
	//terminated with uncaught exception
	
	cout<<static_cast<double>(a)/b<<endl;
	
    return 0;
}