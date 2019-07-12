#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GetInput {
public:
	GetInput(istream& i = cin): is(i) {}
	string operator()() const{
		string str;
		getline(is,str);
		return is ? str: string();
	}
private:
	istream& is;
};

int main()
{
    GetInput gi;
	vector<string> vec;
	for(string temp; !(temp=gi()).empty();)
		vec.push_back(temp);
	for(const auto& str:vec)
		cout<<str<<" ";
	cout<<endl;
    return 0;
}