#include <iostream>
#include "../ex20/Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if(std::cin>>currItem){
        int count = 1;
        while(std::cin>>valItem){
            if(valItem.isbn()==currItem.isbn()){
                ++count;
            }else{
                std::cout<<currItem<<" occurs "<<count<<" times "<<std::endl;
                currItem = valItem;
                count=1;
            }
        }
        std::cout<<currItem<<" occurs "<<count<<" times "<<std::endl;
    }else{
        std::cerr<<"No data?"<<std::endl;
        return -1;
    }
    return 0;
}