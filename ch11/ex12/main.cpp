#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<pair<string,int>> vec;
    string str;
    int i;
    while(cin>>str>>i)
        vec.push_back(pair<string,int>(str,i));
        vec.push_back(make_pair(str,i));
        vec.push_back({str,i});
        vec.emplace_back(str,i);
    for(const auto&p : vec)
        cout<<p.first<<":"<<p.second<<endl;
	return 0;
}
