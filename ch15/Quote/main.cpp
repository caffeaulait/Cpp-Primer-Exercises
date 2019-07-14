#include <iostream>
#include "Quote.h"
#include <vector>
#include <numeric>
#include <memory>

int main()
{
//  Quote quote_03("0-201-78345-X", 23.8);
//  print_total(cout, quote_03, 3);
//	
//	Bulk_Quote bulk_quote("0-201-78345-X", 23.8, 3, 0.5);
//	print_total(cout, bulk_quote, 4);
//	
//	Limit_Quote limit_quote("0-201-78345-X", 23.8, 3, 5, 0.5);
//  print_total(cout, limit_quote, 6);
	
	
	vector<shared_ptr<Quote>> vecQuote;
	
    shared_ptr<Bulk_Quote> bulk0 = make_shared<Bulk_Quote>("0-201-82470-1", 50, 5, 0.2);
    shared_ptr<Bulk_Quote> bulk1 = make_shared<Bulk_Quote>("0-201-82470-1", 50, 3, 0.5);
	
    cout << "bulk_quote's total: " << bulk0->net_price(5) + bulk1->net_price(5) << endl;
	
	vecQuote.push_back(bulk0);
	vecQuote.push_back(bulk1);
	
	double total = accumulate(vecQuote.cbegin(),vecQuote.cend(),0.0,[](double ret,shared_ptr<Quote> sp){
		return ret += sp->net_price(5);	
	});
	
    cout << "total in the vector: " << total << endl;	
    return 0;
}