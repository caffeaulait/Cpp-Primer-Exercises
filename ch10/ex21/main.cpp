#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int local_val = 7;
    auto decrement_to_zero = [&local_val]() ->bool {
        if(local_val == 0)
            return true;
        else
            --local_val;
            return false;
    };
    
    while(!decrement_to_zero())
        cout<<local_val<<endl;
	return 0;
}
