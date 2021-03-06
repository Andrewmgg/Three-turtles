#include <iostream>
#include <string>
#include <cmath>
#include <ctype>

using namespace std;

double stdC[26] = {8.17, 1.49, 2.78, 4.25, 12.7, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.01, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};

double cnt[26];
int d;
string res;

char h2c(char h) {
    if (h >= '0' && h <='9')
        h = h-'0';
    else if (h >= 'A' && h <='F')
        h = h-'A'+10;
    return h;
}

void Vizyner(char* s, int sL, int* key, int keyL) {
    for (int i = 0; i < 26; ++i)
        cnt[i] = 0;
    d = 0;

    res = "";
    int j = 0;
    for (int i = 0; i < sL; ++i) {
        char dc = s[i] ^ (char)(key[j]);
        
        res += dc;
        if(isalpha(dc)) {
            cnt[toupper(dc)-'A'] += 1;
            ++d;
        }
        j = (j + 1) % keyL;
    }
    
    for (int j = 0; j < 26; ++j)
        cnt[j] *= 100.0 / d;
}

bool isAKey(char* s, int sL, int* key, int keyL) {
    res = "";
    int i = 0;
    int j = 0;
    while (i < sL) {
        if (key[j] == -1) {
            i += keyL-j;
            j = 0;
            continue;
        }
        char dc = s[i] ^ (char)(key[j]);
        if (!isprint(dc)) {
            return false;
        }
        ++i;
        j = (j + 1) % keyL;
    }
    return true;
}

double summ() {
    double s = 0;
    for (int i = 0; i < 26; ++i)
        s += abs(stdC[i] - cnt[i])*cnt[i];
    return s;
}

int main() {
    string s;
    //std::getline(std::cin, s);
    
    s = "F96DE8C227A259C87EE1DA2AED57C93FE5DA36ED4EC87EF2C63AAE5B9A7EFFD673BE4ACF7BE8923CAB1ECE7AF2DA3DA44FCF7AE29235A24C963FF0DF3CA3599A70E5DA36BF1ECE77F8DC34BE129A6CF4D126BF5B9A7CFEDF3EB850D37CF0C63AA2509A76FF9227A55B9A6FE3D720A850D97AB1DD35ED5FCE6BF0D138A84CC931B1F121B44ECE70F6C032BD56C33FF9D320ED5CDF7AFF9226BE5BDE3FF7DD21ED56CF71F5C036A94D963FF8D473A351CE3FE5DA3CB84DDB71F5C17FED51DC3FE8D732BF4D963FF3C727ED4AC87EF5DB27A451D47EFD9230BF47CA6BFEC12ABE4ADF72E29224A84CDF3FF5D720A459D47AF59232A35A9A7AE7D33FB85FCE7AF5923AA31EDB3FF7D33ABF52C33FF0D673A551D93FFCD33DA35BC831B1F43CBF1EDF67F0DF23A15B963FE5DA36ED68D378F4DC36BF5B9A7AFFD121B44ECE76FEDC73BE5DD27AFCD773BA5FC93FE5DA3CB859D26BB1C63CED5CDF3FE2D730B84CDF3FF7DD21ED5ADF7CF0D636BE1EDB79E5D721ED57CE3FE6D320ED57D469F4DC27A85A963FF3C727ED49DF3FFFDD24ED55D470E69E73AC50DE3FE5DA3ABE1EDF67F4C030A44DDF3FF5D73EA250C96BE3D327A84D963FE5DA32B91ED36BB1D132A31ED87AB1D021A255DF71B1C436BF479A7AF0C13AA14794";
    string key = "BA1F91B253CD3E";

    // HEX-������ � ������ �����
    int stL = s.size() / 2;
    char *st = new int(stL);
    for (unsigned int i = 0; i < s.size(); i+=2) {
        st[i/2] = h2c(hex[i])*16 + h2c(hex[i+1]);
    
    // ���������� ����� �����
    int keyL = 7;
    
    // ��������� ���� �������� �����
    int k[13] = {0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int bestK[13];
    double mins = 100500;
    
    int cur = 0;
    while (cur < keyL) {
        for(int j = 0; j < 128; ++j) {
            k[cur] = j;
            if (!isAKey(st, stL, k, keyL)) continue;
            ++cur;
            if (cur == keyL) { // key is valid
                Vizyner(st, stL, k, keyL);
                double c = summ();
                if (c < mins) {
                    mins = c;
                    mink = i;
                }
            }
        }
    }
    
    cout << key << endl << res;
    delete st;
    return 0;
}