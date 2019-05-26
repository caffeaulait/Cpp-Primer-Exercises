#include <iostream>

size_t generate(){
	static size_t ctr = 0;
	return ctr++;
}

int main()
{
    for(int i =0;i<10;i++)
		std::cout<<generate()<<std::endl;
    return 0;
}