#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    // use string.
    string s1("cafe");
    string s2("lait");

    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "cafe > lait" << endl;
    else
        cout << "cafe < lait" << endl;

    cout << "=========" << endl;
    // use C-Style character strings.
    const char* cs1 = "cafe";
    const char* cs2 = "lait";

    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "cafe < lait" << endl;
    else
        cout << "cafe > lait" << endl;

    return 0;
}