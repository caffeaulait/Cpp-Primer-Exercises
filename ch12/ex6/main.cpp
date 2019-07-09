#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

vector<int>* generator();
void processor(vector<int>* ptr);
void printer(vector<int>* ptr);


int main()
{
    vector<int>* p = generator();
	processor(p);
	printer(p);
	delete p;
    return 0;
}

vector<int>* generator(){
	return new vector<int>();
}

void processor(vector<int>* ptr){
	int i;
	cout<<"enter numbers:\n";
	while(cin>>i)
		ptr->push_back(i);
	
}

void printer(vector<int>* ptr){
	for(auto& e : *ptr)
		cout<<e<<" ";
	cout<<endl;
}