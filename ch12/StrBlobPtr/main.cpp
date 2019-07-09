#include <iostream>
#include <memory>
#include <vector>
#include "../StrBlob/StrBlob.h"
using namespace std;

class StrBlobPtr{
	friend class StrBlob;
public:
	StrBlobPtr(): curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz =0):
		wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	
private:
	shared_ptr<vector<string>> check(size_t,string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i,string& msg) const{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("Unbound StrBlobPtr");
	if(i>=ret->size())
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	check(curr,"increment past end");
	++curr;
	return *this;
}

int main()
{

    return 0;
}

