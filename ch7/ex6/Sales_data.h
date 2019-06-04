#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
using namespace std;

class Sales_data
{
	friend ostream& print(ostream& os, const Sales_data& item);
	friend istream& read(istream& is, Sales_data& item);
	friend Sales_data add (const Sales_data& lhs, const Sales_data& rhs);

	string bookNo;
	unsigned units_sold=0;
	double revenue=0.0;
	
public:
	string const& isbn() const{
		return bookNo;
	}
	
	Sales_data& combine(const Sales_data&);
	
	Sales_data()= default;
	Sales_data(const string& s):bookNo(s){}
	Sales_data(const string& s, unsigned n, double p):
		bookNo(s),units_sold(n),revenue(n*p) {}
	Sales_data(istream& is);
	~Sales_data();

};

//ostream& print(ostream& os, const Sales_data& item);
//istream& read(istream& is, Sales_data& item);
//Sales_data add (const Sales_data& lhs, const Sales_data& rhs);


#endif // SALES_DATA_H
	