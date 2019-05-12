#include <iostream>


template <int N>
class Array {
	int size {N};
	int values[N];
	
	friend std::ostream &operator<<(std::ostream &os, const Array<N>& arr){
		os<<"[ ";
		for(const auto &val:arr.values)
			os << val <<" ";
		os<<"]"<<std::endl;
		return os;
	}
	
public:
	Array() = default;
	Array(int init_val){
		for(auto &item : values)
			item = init_val;
	}
	
	void fill(int val){
		for(auto &item : values){
			item =val;
		}
	}
	
	int get_size() const{
		return size;
	}
	
	int& operator[](int index){
		return values[index];
	}

};

int main(){
	Array<5> nums;
	nums.fill(100);
	std::cout<<"THE SIZE OF NUMS IS: "<<nums.get_size()<<std::endl;
	std::cout<<nums<<std::endl;
	return 0;
}