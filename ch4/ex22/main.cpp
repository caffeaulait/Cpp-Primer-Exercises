#include <iostream>
using namespace std;

int main()
{
    unsigned grade;
	while(cin>>grade)
		cout<<((grade>90)?"high pass":(grade<60)?"fail":(grade<75)?"low pass":"pass");
		cout<<endl;
    return 0;
}