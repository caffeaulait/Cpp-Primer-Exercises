#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include <pair>

using namespace std;

class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	
	StrVec(const StrVec&);
	
	StrVec &operator=(const StrVec&);
	
	~StrVec() {free();}
	
	void push_back(const string&);
	
	size_t size() const {
		return first_free - elements;
	}
	
	size_t capacity() const {
		return cap - elements;
	}
	
	string *begin() const{
		return elements;
	}
	
	string *end() const {
		return first_free;
	}
	
	string& operator[](size_t n){
		return elements[n];
	}
	
	const string& operator[](size_t n)const{
		return elements[n];
	}

private:
	string *elements;
	string *first_free;
	string *cap;
	
	allocator<string> alloc;
	
	void check_alloc(){
		if(size()==capacity())
			reallocate();
	}
	pair<string*, string*> alloc_copy(const string*, const string*);
	void free();
	void reallocate();
};

void StrVec::push_back(const string& s){
	check_alloc();
	alloc.construct(first_free++,s);
}

pair<string*, string*> StrVec::alloc_copy(const string *b, const string *e){
	auto data = alloc.allocate(e-b);
	return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free(){
	if(elements){
		for(auto p = first_free; p!=elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements,cap-elements);
	}
}

StrVec::StrVec(const StrVec &s){
	auto newdata = alloc_copy(s.begin(),s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec& StrVec::operator =(const StrVec &rhs){
	auto data = alloc_copy(rhs.begin(),rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate(){
	auto newCapacity = size() ? 2*size() : 1;
	auto newdata = alloc.allocate(newCapacity);
	auto dest = newdata;
	
	auto elem = elements;
	for(size_t i =0;i!=size();++i)
		alloc.construct(dest++,move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newCapacity;
}

#endif // STRVEC_H
