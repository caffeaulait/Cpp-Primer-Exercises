#include <iostream>
#include <string>
#include <vector>
using namespace std;

//template classes are typically completely contained in header files, no cpp file

template <typename T>
class Item{
private:
    string name;
    T value;
public:
    Item () = default;
    Item (string name, T value):name(name),value(value){}
    string get_name() const{ return name;}
    T get_value() const{ return value;}

};

template <typename T1, typename T2>
struct My_Pair{
    T1 first;
    T2 second;
};

int main(int argc, char **argv)
{
    Item<int> item1 {"Yang",100};
    cout<<item1.get_name()<<" "<<item1.get_value()<<endl;
    
    Item<Item<string>> item2 {"Yang",{"C++","hard"}};
    cout<<item2.get_name()<<" "<<item2.get_value().get_name()<<" "<<
        item2.get_value().get_value()<<endl;
    My_Pair <string,int> p1 {"Yang",100};
    My_Pair <int,double> p2 {121,10.0};
    
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
	return 0;
}
