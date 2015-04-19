#include <iostream>
#include <math.h>
#define MAX 1000000

using namespace std;

int par(int input)
{
    int res =0;
    while(input)
    {
        res += (input & 1);
        input >>= 1;
    }
    if(res % 2 == 0) return 1;
    else return 0;
}

int nod(int a, int b)
{
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a | b;
}

int f_euler_rec(int n)
{
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main()
{
    int p, q, x0, k, r;
    cin >> p >> q >> x0 >> k >> r;

    if((p < MAX) && (q < MAX) && (p % 4 == 3) && (q % 4 == 3) && (nod(f_euler_rec(p-1), f_euler_rec(q-1)) <= 3))
    {
        long m = p * q;
        int array[8 * r];
        int x = x0;
        for(int i = 0; i < 8 * k; ++i)
        {
            x = (x * x) % m;
        }

        for(int i = 8 * k; i < 8 * (k + r); ++i)
        {
            array[i - 8 * k] = par(x);
            cout << array[i - 8 * k];
            x = (x * x) % m;
        }

        cout << endl;

        for(int i = 0; i < 8 * r; i += 4)
        {
            int code = (array[i] << 3) + (array[i + 1] << 2) + (array[i + 2] << 1) + array[i + 3];
            if (code >= 10)
            {
                code -= 10;
                cout << (char)('a' + code);
            } else
            {
                cout << code;
            }
        }
        cout << endl;
    }
    else
    {
        cout<<"no";
    }
    return 0;
}
