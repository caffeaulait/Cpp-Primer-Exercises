#include <iostream>
#include "../ex20/Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin>>item1>>item2;
    if(item1.isbn() == item2.isbn()){
        std::cout<<item1+item2<<std::endl;
    }else{
        std::cerr<<"Book must refer to the same ISBN."<<std::endl;
    }
    return 0;
}