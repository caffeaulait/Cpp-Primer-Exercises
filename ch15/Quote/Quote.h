#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>
using namespace std;

class Quote
{
public:

	Quote() = default;
	
	Quote(const string& book, double sales_price):
		bookNo(book), price(sales_price)	{}
		
	virtual ~Quote()=default;
	
	string isbn() const {
		return bookNo;
	}
	
	virtual double net_price(size_t n) const{
		return n*price;
	}
	
	virtual void debug() const {
		cout << "data members: \n" << "\tbookNo: " << 
			bookNo << "\tprice: " << price << endl; 
	}
	
private:
	string bookNo;

protected:
	double price = 0.0;

};

class Disc_Quote : public Quote
{
public:
	Disc_Quote() = default;
	Disc_Quote(string const&book, double p ,size_t qty, double disc):
		Quote(book,p), quantity(qty), discount(disc){}
			
	virtual double net_price(size_t n) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};


class Bulk_Quote : public Disc_Quote
{
public:
	Bulk_Quote()=default;
	
	Bulk_Quote(const string& book, double p, size_t qty, double disc):
		Disc_Quote(book, price, qty, disc){}
	
	virtual double net_price(size_t n) const override{
		if( n >= quantity)
			return n * (1-discount)*price;
		else 
			return n * price;
	}
	
	virtual void debug() const override {
        Quote::debug();
        cout << "\tminqty: " << quantity << "\tdiscount: " << discount << endl;
    }	
};



class Limit_Quote : public Disc_Quote{
public:
	Limit_Quote()=default;
	
	Limit_Quote(const string& book, double p, size_t min, size_t max, double disc):
		 Disc_Quote(book, p, min, disc), max_qty(max){}
	
	virtual double net_price(size_t cnt) const override{
		if (cnt > max_qty) 
			return max_qty*(1-discount)*price + (cnt-max_qty)*price;
		else if ( cnt >= quantity)
			return cnt * (1-discount)*price;
		else 
			return cnt * price;
	}
	
    virtual void debug() const final {
        Disc_Quote::debug();
        cout << "\tmax_qty: " << max_qty << endl;
    }
private:
	size_t max_qty = 0;
};


//dynamic binding happends when a virtual function is called
//through a reference(or a pointer) to a base class
double print_total(ostream &os, const Quote &item, size_t n){
	double ret = item.net_price(n);
	os<<"ISBN: "<<item.isbn()<<" # sold: "<<
		n<<" total due: "<<ret<<endl;
	return ret;
}


#endif // QUOTE_H
