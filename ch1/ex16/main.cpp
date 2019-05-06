#include <iostream>

int main()
{
    int val =0, sum =0;
    std::cout<<"please enter some numbers and press Crtl-d if finished: ";
    while(std::cin>>val){
        sum+=val;
    }
    std::cout<<"the sum of entered numbers is: "<<sum<<std::endl;
    return 0;
}