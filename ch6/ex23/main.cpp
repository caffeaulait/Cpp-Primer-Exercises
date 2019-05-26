#include <iostream>
using namespace std;


void print(int* const pi){
	if(pi)
		cout<<*pi<<endl;
}

void print(const char* p){
	if(p)
		while(*p)
			cout<<*p++;
	cout<<endl;
}

void print(const int* beg,const int* end){
	while(beg!=end)
		cout<<*beg++<<" ";
	cout<<endl;
}

void print(const int ia[], size_t size){
	for(size_t i =0;i!=size;++i)
		cout<<ia[i]<<" ";
	cout<<endl;
}

void print(const int (&arr)[2]){
	for(auto i : arr)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{	
	int i = 0, j[2] = {0, 1};
    char ch[5] = "pezy";
    print(ch);
	print(begin(j),end(j));
	print(j,end(j)-begin(j));
	print(&i);
//	print(j); error, call be both the first and last function
	print(const_cast<const int (&)[2]>(j));
	
	
	
    return 0;
}