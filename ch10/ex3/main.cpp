#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> v1 = {1,2,3,4};
    cout<<accumulate(v1.cbegin(),v1.cend(),0)<<endl;
    
    vector<double> v2 = {1.1,0.5,3,3};
    cout<<accumulate(v2.cbegin(),v2.cend(),0)<<endl;
	return 0;
}
