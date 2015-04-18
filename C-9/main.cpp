#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double stdC[26] = {8.17, 1.49, 2.78, 4.25, 12.7, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.01, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};

double cnt[26];
int d;

string caesar(string s, int k) {
    string t;

    for (int i = 0; i< 26; ++i)
        cnt[i] = 0;
      
    d = 0;
    
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s[i] < 'A' || s[i] > 'Z') {
            t += s[i];
            continue;
        }
        d++;
        int tmp = (s[i] - 'A') - k;
        if (tmp < 0)
            tmp += 26;
        char c = tmp + 'A';
        t += c;
        cnt[c-'A'] += 1;
    }
    
    for (int j = 0; j < 26; ++j)
        cnt[j] *= 100.0 / d;
        
    return t;
}

double summ() {
    double s = 0;
    for (int i = 0; i < 26; ++i)
        s += abs(stdC[i] - cnt[i]);
    return s;
}

int main() {
    string s;
    cin >> s;
    string t;
    
    double mins = 100500;
    int mink = -1;
    
    for (int i = 0; i < 26; i++) {
        t = caesar(s, i);
        double c = summ();
        if (c < mins) {
            mins = c;
            mink = i;
        }
    }
    
    cout << mink << endl << caesar(s, mink);
    return 0;
}
