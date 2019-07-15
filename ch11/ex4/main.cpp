#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


void word_count(map<string,int>& m){
    string word;
    while(cin>>word){
        for(auto& ch : word)
            ch = tolower(ch);
        word.erase( remove_if(word.begin(),word.end(),::ispunct),word.end());
        ++m[word];
    }
    for(const auto& e:m)
        cout<<e.first<<": "<<e.second<<"\n";
}




int main(int argc, char **argv)
{
    map<string,int> m;
    word_count(m);
	return 0;
}
