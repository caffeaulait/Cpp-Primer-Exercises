#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    map<string,size_t> word_count;
    string word;
    while(cin>>word){
        auto ret = word_count.insert({word,1});
        if(!ret.second)
            ++ret.first->second;
    }
    
    for(const auto& w: word_count)
        cout<<w.first<<" "<<w.second<<
            ((w.second>1)?" times":" time")<<endl;
	return 0;
}
