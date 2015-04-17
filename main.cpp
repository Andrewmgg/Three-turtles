#include <iostream>
#include <cstdlib>
#include <math.h>
#define temp 100
#define int64 unsigned long long
using namespace std;

class RSA
{
private:
    int64 p;
    int64 q;
    int64 N, M;
    
public:

    RSA(int64 p, int64 q)
    {
        this->p = p;
        this->q = q;

        this->N = p * q;
        this->M = (p - 1) * (q - 1);
    }

    int64 e()
    {
        int64 e;
        do
        {
            //int64 degree = (int64)(random() % 5);
            //e = (1 << degree) + 1;
            e = 3;
        }
        while(nod(e, this->M) > 1);
        return e;
    }

    int64 d()// работает если существует обратный элемент
    {
        int64 res = 0;
        int64 e = this->e();
        //int m = this->m();
        while((e * res) % this->M != 1)
            res++;
        return res;
    }

    int64 nod(int64 a, int64 b)
    {
        while (a && b) {
            if (a >= b)
                a %= b;
            else
                b %= a;
        }
        return a | b;
    }

    int64 encode(int64 text)
    {
        int64 res = 1;
        for (int n = this->N, e = this->e(), i = 0; i < e; ++i)
            res = (res * text) % n;
        return res;
    }

    int64 decode(int64 ctext)
    {
        int64 res = 1;
        for (int64 n = this->N, d = this->d(), i = 0; i < d; ++i)
            res = (res * ctext) % n;
        return res;
    }
};


int main()
{
    int64 p,q;
    p = 3557;
    q = 2579;
    //cin>>p>>q;
    RSA rsa(p, q);
    int64 text;
    cin >> text;
    int64 cod = rsa.encode(text);
    cout << cod << endl;
    int64 decod = rsa.decode(cod);
    cout << decod << endl;


    return 0;
}
