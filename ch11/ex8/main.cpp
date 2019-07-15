#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//inserting or deleting an element from a vector is more expensive than that in a set
int main(int argc, char **argv)
{
    string word;
    vector<string> exclude = {"aa","bb","cc"};
    while(cin>>word){
        if(find(exclude.begin(),exclude.end(),word)!=exclude.end())
            cout<<"excluded!"<<endl;
        else 
            exclude.push_back(word);
    }
    
    for(auto const& s : exclude)
        cout<<s<<" ";
    cout<<endl;
	return 0;
}
