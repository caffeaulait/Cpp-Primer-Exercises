#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>;
using namespace std;

class Person
{
	friend istream& read(istream& is, Person& person);
	friend ostream& print(ostream& os, const Person& person);
	
	string name;
	string address;
	
public:

	Person()= default;
	~Person();
	
	Person(const string sname, const string saddress):
		name(sname),address(saddress){}
	
	Person(istream& is);
	
	const string& getName() const{
		return name;
	}
	
	const string& getAddress() const{
		return address;
	}
};

//istream& read(istream& is, Person& person);
//
//ostream& print(ostream& os, const Person& person);

#endif // PERSON_H
