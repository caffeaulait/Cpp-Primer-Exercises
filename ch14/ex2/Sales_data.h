#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
	friend istream& operator>>(istream&, Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
	Sales_data(const string&s, unsigned n, double p):
		bookNo(s), units_sold(n),revenue(n*p){}
		
	Sales_data(): Sales_data("",0,0.0f){}
	
	Sales_data(const string &s) : Sales_data(s,0,0.0f){}
	
	Sales_data(istream& is);
	
	Sales_data& operator+=(const Sales_data&);
	
	string isbn() const {
		return bookNo;
	}
	
	~Sales_data();
	
	
	
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const {
		return units_sold? revenue/units_sold : 0;
	}
};

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

#endif // SALES_DATA_H
