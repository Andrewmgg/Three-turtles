#include <iostream>
#include <math.h>
#define MAX 1000000

using namespace std;

long par(long input)
{
    long res =0;
    while(input)
    {
        res += (input & 1);
        input >>= 1;
    }
    if(res % 2 == 0) return 1;
    else return 0;
}

long nod(long a, long b)
{
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a | b;
}

long f_euler_rec(long n)
{
	long result = n;
	for (long i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


long binpow (long a, long n) {
	long res = 1;
	while (n) {
		if (n & 1)
			res = (res * a);
		a = (a * a);
		n >>= 1;
	}
	return res;
}

long powermod(long base, long exponent, long modulus) {
    if (base < 1 || exponent < 0 || modulus < 1)
        return -1;

    long result = 1;
    while (exponent > 0) {
       if (exponent & 1) {
           result = (result * base) % modulus;
       }
       base = (base * base) % modulus;
       exponent >>= 1;
    }
    return result;
}


int main()
{
    long p, q, x0, k, r;
    cin >> p >> q >> x0 >> k >> r;

    if((p < MAX) && (q < MAX) && (p % 4 == 3) && (q % 4 == 3) && (nod(f_euler_rec(p-1), f_euler_rec(q-1)) <= 3))
    {
        long m = p * q;
        long array[8 * r];
        long x = x0;
        x = powermod(x0, binpow(2, 8 * k), m);
        //for(long i = 0; i < 8 * k; ++i)
        //{
        //    x = (x * x) % m;
        //}

        for(long i = 8 * k; i < 8 * (k + r); ++i)
        {
            array[i - 8 * k] = par(x);
            cout << array[i - 8 * k];
            x = (x * x) % m;
        }

        cout << endl;

        for(long i = 0; i < 8 * r; i += 4)
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
