#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ctext, text = "";
    cin >> ctext;
    for (int i = 0, l = ctext.size(); i < l; ++i)
    {
        text += (char)(ctext[i] + 1);
        if (text[i] == '{')
            text[i] = 'a';
    }
    cout << text << endl;
    return 0;
}
