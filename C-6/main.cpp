#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char* decodeUTF8(int* codeText, int len)
{
    char* str = new char[len];
    int cnt = 0;

    for (int i = 0; i < len;)
    {
        int bytes = 0;
        if (codeText[i] & 0x80)
        {
            bytes++;
            if (codeText[i] & 0x40)
            {
                bytes++;
            }
        }

        int code = 0;
        for (int j = bytes - 1; j > 0; j--)
        {
            code += codeText[i + j] & 0x3F;
        }

        if (bytes == 2)
        {
            code += (codeText[i] & 0x1F) << 8;
        } else
        {
            code += codeText[i] & 0x3F;
        }

        str[cnt] = (char) code;
        i += bytes;
        cnt++;
    }

    return str;
}

int main()
{
    string ctext, text = "";
    cin >> ctext;
    int *codeText = new int[ctext.size() / 2];
    for (int i = 0, l = ctext.size(); i < l; i += 2)
    {
        string temp = "";
        for (int j = 0; j < 2; ++j)
        {
            temp += ctext[i + j];
        }
        int code = 0;
        if (0x2F <= (int)temp[0] && (int)temp[0] <= 0x40)
            code += 16 * ((int)temp[0] - 0x30);
        else
            code += 16 * ((int)temp[0] - 0x57);

        if (0x2F <= (int)temp[1] && (int)temp[1] <= 0x40)
            code += 1 * ((int)temp[1] - 0x30);
        else
            code += 1 * ((int)temp[1] - 0x57);
        codeText[i / 2] = code;
    }
    cout << decodeUTF8(codeText, ctext.size() / 2) << endl;
}
