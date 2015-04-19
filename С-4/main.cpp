#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    string* koi_mapping = new string[256];
    koi_mapping[0xC0] = "fe";
    koi_mapping[0xC1] = "e0";
    koi_mapping[0xC2] = "e1";
    koi_mapping[0xC3] = "f6";
    koi_mapping[0xC4] = "e4";
    koi_mapping[0xC5] = "e5";
    koi_mapping[0xC6] = "f4";
    koi_mapping[0xC7] = "e3";
    koi_mapping[0xC8] = "f5";
    koi_mapping[0xC9] = "e8";
    koi_mapping[0xCA] = "e9";
    koi_mapping[0xCB] = "ea";
    koi_mapping[0xCC] = "eb";
    koi_mapping[0xCD] = "ec";
    koi_mapping[0xCE] = "ed";
    koi_mapping[0xCF] = "ef";

    koi_mapping[0xD0] = "ef";
    koi_mapping[0xD1] = "ff";
    koi_mapping[0xD2] = "f0";
    koi_mapping[0xD3] = "f1";
    koi_mapping[0xD4] = "f2";
    koi_mapping[0xD5] = "f3";
    koi_mapping[0xD6] = "e6";
    koi_mapping[0xD7] = "e2";
    koi_mapping[0xD8] = "fc";
    koi_mapping[0xD9] = "fb";
    koi_mapping[0xDA] = "e7";
    koi_mapping[0xDB] = "f8";
    koi_mapping[0xDC] = "fd";
    koi_mapping[0xDD] = "f9";
    koi_mapping[0xDE] = "f7";
    koi_mapping[0xDF] = "fa";

    koi_mapping[0xE0] = "de";
    koi_mapping[0xE1] = "c0";
    koi_mapping[0xE2] = "c1";
    koi_mapping[0xE3] = "c6";
    koi_mapping[0xE4] = "c4";
    koi_mapping[0xE5] = "c5";
    koi_mapping[0xE6] = "c4";
    koi_mapping[0xE7] = "c3";
    koi_mapping[0xE8] = "d5";
    koi_mapping[0xE9] = "c8";
    koi_mapping[0xEA] = "c9";
    koi_mapping[0xEB] = "ca";
    koi_mapping[0xEC] = "cb";
    koi_mapping[0xED] = "cc";
    koi_mapping[0xEE] = "cd";
    koi_mapping[0xEF] = "ce";

    koi_mapping[0xF0] = "cf";
    koi_mapping[0xF1] = "df";
    koi_mapping[0xF2] = "d0";
    koi_mapping[0xF3] = "d1";
    koi_mapping[0xF4] = "d2";
    koi_mapping[0xF5] = "d3";
    koi_mapping[0xF6] = "c6";
    koi_mapping[0xF7] = "c2";
    koi_mapping[0xF8] = "dc";
    koi_mapping[0xF9] = "db";
    koi_mapping[0xFA] = "c7";
    koi_mapping[0xFB] = "d8";
    koi_mapping[0xFC] = "dD";
    koi_mapping[0xFD] = "d9";
    koi_mapping[0xFE] = "d7";
    koi_mapping[0xFF] = "da";

    string ctext, text = "";
    cin >> ctext;
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
        int offset = (i / 2) % 26;
        text += (char)((code + offset > 0x7a) ? (code + offset - 26) : (code + offset));
    }
    cout << text << endl;
}
