#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double stdC[26] = {8.17, 1.49, 2.78, 4.25, 12.7, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.01, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};

int k1_[11] = {3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

double cnt[26];
int d;

string caesar(string s, int k1, int k2) {
    string t;

    for (int i = 0; i< 26; ++i)
        cnt[i] = 0;

    d = 0;

    int k_1 = 0;
    for (int i = 1; i < 26; ++i)
        if ((k1 * i) % 26 == 1)
        {
            k_1 = i;
            break;
        }

    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s[i] < 'A' || s[i] > 'Z') {
            t += s[i];
            continue;
        }
        d++;
        int tmp = (((s[i] - 'A') - k2) * k_1) % 26;
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
        s += abs(stdC[i] - cnt[i])*cnt[i];
    return s;
}

int main() {
    string s;
    std::getline(std::cin, s);
    //cin >> s;
    string t;

    double mins = 100500;
    int mink1 = 0, mink2 = 0;

    for (int j = 0; j < 11; ++j)
    {
        for (int i = 0; i < 26; i++) {
            t = caesar(s, k1_[j], i);
            double c = summ();
            if (c < mins) {
                mins = c;
                mink1 = k1_[j];
                mink2 = i;
            }
        }
    }

    cout << mink1 << endl << mink2 << endl;
    cout << caesar(s, mink1, mink2) << endl;

    //cout << mink << endl << caesar(s, mink);
    return 0;
}
