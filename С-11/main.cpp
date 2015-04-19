#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double stdC[26] = {8.17, 1.49, 2.78, 4.25, 12.7, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.01, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};

int compareDouble (const void * a, const void * b)
{
  if ( *(double*)a >  *(double*)b ) return -1;
  if ( *(double*)a == *(double*)b ) return 0;
  if ( *(double*)a <  *(double*)b ) return 1;
  return 0;
}

double calcCost(double* freqs)
{
    double res = 0;
    qsort(freqs, 26, sizeof(double), compareDouble());
    for (int i = 0; i < 26; ++i)
    {
        res += abs(stdC[i] - freqs[i]);
    }
    return res;
}

int main()
{
    string ctext, text = "";
    int *codeText;
    cin >> ctext;
    codeText = new int[ctext.size() / 2];

    for (int i = 0, l = ctext.size(); i < l; i += 2)
    {
        string temp = "";
        for (int j = 0; j < 2; ++j)
        {
            temp += ctext[i + j];
        }
        int code = 0;
        if ('0' <= (int)temp[0] && (int)temp[0] <= '9')
            code += 16 * ((int)temp[0] - '0');
        else
            code += 16 * ((int)temp[0] - 'A' + 10);

        if ('0' <= (int)temp[1] && (int)temp[1] <= '9')
            code += 1 * ((int)temp[1] - '0');
        else
            code += 1 * ((int)temp[1] - 'A' + 10);
        codeText[i / 2] = code;
    }

    qsort(stdC, 26, sizeof(double), compareDouble);
    for (int i = 0; i < 26; ++i)
        cout << stdC[i] << endl;

    double minCost = 100500.0;
    double* minFreq = new double[256];
    for (int i = 1; i < 14; ++i)
    {
        double cost = 0.0;
        double* freqs = new double[256];
        for (int j = 0, l = ctext.size() / 2; j < l; j += i)
        {
            freqs[codeText[j]] += 1;
        }
        cost = calcCost(freqs);

        if (cost < minCost)
        {
            minCost = cost;
            minFreq = freqs;
        }
    }
}
