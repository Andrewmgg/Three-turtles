#include <iostream>
#include <math.h>
#define MAX 1000000

using namespace std;

class BBS
{
    private:
    int p;
    int q;
    int x0;
    public:
    BBS(int p,int q, int x0)
    {
        this->p=p;
        this->q=q;
        this->x0=x0;
    }
    int value_n(int number)
    {
        int i=0;
        int ans=x0;
        while(i<number)
        {
            ans=(ans*ans)%(p*q);
        }
        if(number ==0) return x0;
        return ans;
    }

    int par(int input)
    {
        int res =0;
        while(input)
        {
            res+=(input & 1);
            input>>=1;
        }
        if(res%2==0)return 1;
        else return 0;
    }

};

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
    int ans=n;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) {
            while (n % i == 0) n/= i;
            ans-=ans/i;
        }
        if (n > 1) ans-=ans/n;
    }
    return ans;
}

int main()
{
    int p,q,x0,k,r;
    cin>>p>>q>>x0>>k>>r;
    if(p<MAX && q<MAX && p%4==3 && q%4==3 && nod(f_euler_rec(p-1),f_euler_rec(q-1))<=3)
    {
        BBS bbs(p,q,x0);
        int array[8*(k+r+1)];
        for(int i=0;i<8*(k+r+1);++i)
        {
            array[i]=bbs.par(bbs.value_n(i));
        }
        for(int i=8*k;i<8*(k+r+1);++i)
        {
            cout<<array[i];
        }
    }
    else
    {
        cout<<"no";
    }
    return 0;
}
