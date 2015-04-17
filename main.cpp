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
        this->p=p;
        this->q=q;
    }
    int n()
    {
        return p*q;
    }
    int m()
    {
        return (p-1)*(q-1);
    }
    int e()
    {
        int e;
        do
        {
            e=rand()%temp;
        }
        while(nod(e,m())>1);
        return e;

    }
    int d()// работает если существует обратный элемент
    {
        int res=0;
        while(e()*res%(m())!=1)
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
};


int main()
{
    int p,q;
    p=3557;
    q=2579;
    //cin>>p>>q;
    RSA rsa(p,q);
    int text;
    cin>>text;
    int cod = fmod(pow(text,rsa.e()),rsa.n());
    cout<<cod<<endl;
    int decod = fmod(pow(cod,rsa.d()),rsa.n());
    cout<<decod<<endl;


    return 0;
}
