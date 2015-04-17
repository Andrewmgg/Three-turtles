#include <iostream>
#include <cstdlib>
#include <math.h>
#define temp 100
using namespace std;

class RSA
{
private:
    int p;
    int q;
public:

    RSA(int p, int q)
    {
        this->p = p;
        this->q = q;
    }

    long n()
    {
        return p * q;
    }

    int m()
    {
        return (p - 1) * (q - 1);
    }

    int e()
    {
        int e;
        do
        {
            //int degree = (int)(random() % 5);
            //e = (1 << degree) + 1;
            e = 3;
        }
        while(nod(e, m()) > 1);
        return e;
    }

    int d()// работает если существует обратный элемент
    {
        int res = 0;
        int e = this->e();
        int m = this->m();
        while((e * res) % m != 1)
            res++;
        return res;
    }

    int nod(int a, int b)
    {
        while (a && b)

            if (a >= b)
                a %= b;
            else
                b %= a;
        return a | b;
    }

    long encode(int text)
    {
        long res = 1;
        for (int n = this->n(), e = this->e(), i = 0; i < e; ++i)
            res = (res * text) % n;
        return res;
    }

    int decode(long ctext)
    {
        int res = 1;
        for (int n = this->n(), d = this->d(), i = 0; i < d; ++i)
            res = (res * ctext) % n;
        return res;
    }
};


int main()
{
    int p,q;
    p = 3557;
    q = 2579;
    //cin>>p>>q;
    RSA rsa(p, q);
    int text;
    cin >> text;
    long cod = rsa.encode(text);
    cout << cod << endl;
    int decod = rsa.decode(cod);
    cout << decod << endl;


    return 0;
}
