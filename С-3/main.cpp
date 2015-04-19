#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ctext, text = "";
    cin >> ctext;
    for (int i = 0, l = ctext.size(); i < l; i += 8)
    {
        int temp = 0;
        for (int j = 0; j < 8; ++j)
            temp += ctext[i + j] == '1' ? 1 << (7 - j) : 0;
        text += (char)temp;
    }
    cout << text << endl;
}
