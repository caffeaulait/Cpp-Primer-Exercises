#ifndef STRBLOB_H
#define STRBLOB_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StrBlob{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	
	StrBlob():data(make_shared<vector<string>>()){
		}
	
	StrBlob(initializer_list<string> il):
		data(make_shared<vector<string>>(il)){
			}
	
	size_type size() const {
		return data->size();
	}
	
	bool empty() const {
		return data->empty();
	}
	
	void pop_back();
	
	void push_back(const string &s){
		data->push_back(s);
	}
	
	string& front();
	
	string& back();
	
	const string& front() const;
	
	const string& back() const;
	
//	StrBlobPtr begin() {
//		return StrBlobPtr(*this);
//	}
//	
//	StrBlobPtr end(){
//		auto ret = StrBlobPtr(*this, data->size()); return ret; }
	
private:
	shared_ptr<vector<string>> data;
	
	void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const{
	if(i>=data->size())
		throw out_of_range(msg);
}

string& StrBlob::front(){
	check(0,"empty StrBlob");
	return data->front();
}

string& StrBlob::back(){
	check(0,"empty StrBlob");
	return data->back();
}

void StrBlob::pop_back(){
	check(0,"empty StrBlobk");
	data->pop_back();
}

const string& StrBlob::front() const{
	check(0,"empty StrBlob");
	return data->front();
}
	
const string& StrBlob::back() const{
	check(0,"empty StrBlob");
	return data->back();
}
	

#endif // STRBLOB_H
