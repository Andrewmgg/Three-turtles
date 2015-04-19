#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        c = c - 13;
        if (c < 'a') c += 26;
        cout << c;
    }
    return 0;
}
