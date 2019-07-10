#include <string>
using namespace std;


class Employee{
public:
	Employee();
	Employee(const string& name);
	
	const int id() const {
		return id_;
	}
	
	Employee(const Employee&)=delete;
	Employee& operator=(const Employee&)=delete;
	
private:
	string name_;
	int id_;
	static int count;
};

int Employee::count = 0;

Employee::Employee(){
	id_ = count++;
}

Employee::Employee(const string& name){
	id_ = count++;
	name_ = name;
}

int main()
{
    
    return 0;
}