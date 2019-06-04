#include "Person.h"

Person::Person(istream& is){
	read(is,*this);
}
Person::~Person()
{
}

istream& read(istream& is, Person& person){
	is>>person.name>>person.address;
	if(!is)
		person = Person();
	return is;
}

ostream& print(ostream& os, const Person& person){
	os<<person.name<<" "<<person.address;
}