#include <iostream>

int main()
{
    int small =0, big = 0;
    std::cout<<"Please enter two integers: ";
    std::cin>>small>>big;
    if(small>big){
        int temp = small;
        small = big;
        big = temp;
    }
    
    while(small<=big){
        std::cout<<small<<" ";
        ++small;
    }
    
    std::cout<<std::endl;
    return 0;
}