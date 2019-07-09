#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;



shared_ptr<vector<int>> generator();
void processor(shared_ptr<vector<int>> ptr);
void printer(shared_ptr<vector<int>> ptr);



int main()
{
    auto p = generator();
	processor(p);
	printer(p);
    return 0;
}

shared_ptr<vector<int>> generator(){
	return make_shared<vector<int>>();
}

void processor(shared_ptr<vector<int>> ptr){
	int i;
	cout<<"please enter:\n";
	while(cin>>i)
		ptr->push_back(i);
}

void printer(shared_ptr<vector<int>> ptr){
	for(const auto& e: *ptr)
		cout<<e<<" ";
	cout<<endl;
}