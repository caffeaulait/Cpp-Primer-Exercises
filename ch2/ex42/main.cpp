#include <iostream>
#include <string>

struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
	void CalcRevenue(double price);
	double CalcAveragePrice();
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	void Print();
};

void Sales_data::CalcRevenue(double price){
	revenue = units_sold * price;
}

void Sales_data::SetData(Sales_data data){
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
}

void Sales_data::AddData(Sales_data data){
	if(bookNo!=data.bookNo) return;
	units_sold+=data.units_sold;
	revenue+=data.revenue;
}

double Sales_data::CalcAveragePrice(){
	if(units_sold!=0)
		return revenue/units_sold;
	else
		return 0.0;
}

void Sales_data::Print(){
	std::cout<<bookNo<<" "<<units_sold<<" "<<revenue<<" ";
	double avgPrice = CalcAveragePrice();
	if(avgPrice !=0.0)
		std::cout<<avgPrice<<std::endl;
	else
		std::cout<<"no sales"<<std::endl;
}

int main()
{
    Sales_data total;
	double totalPrice;
	if(std::cin >> total.bookNo >> total.units_sold >> totalPrice){
		total.CalcRevenue(totalPrice);
		
		Sales_data trans;
		double transPrice;
		while(std::cin >> trans.bookNo >> trans.units_sold >> transPrice){
			trans.CalcRevenue(transPrice);
			if(total.bookNo==trans.bookNo){
				total.AddData(trans);
			}else{
				total.Print();
				total.SetData(trans);
			}
		}
		total.Print();
		return 0;
	}else{
		std::cerr<<"No data>"<<std::endl;
		return -1;
	}
}