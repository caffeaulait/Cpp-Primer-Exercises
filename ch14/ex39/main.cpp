#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class BoundTest{
public:
	BoundTest(size_t l =0, size_t u =0):
		lower(l),upper(u){}
	bool operator()(const string&s){
		return lower<=s.length()&&s.length()<=upper;
	}

private:
	size_t lower;
	size_t upper;
};

int main()
{
    ifstream fin("/Users/yang/Desktop/leetcode.java");
	size_t quantity9 = 0, quantity10=0;
	BoundTest test9(1,9);
	BoundTest test10(1,10);
	
	for(string word;fin>>word;){
		if(test9(word)) ++quantity9;
		if(test10(word)) ++quantity10;
	}
	
	cout<<quantity9<<" "<<quantity10<<endl;
    return 0;
}