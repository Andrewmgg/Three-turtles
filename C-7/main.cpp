#include <iostream>
#include <vector>
#define dif(x1,x0)(x1)-(x0)
#define len 10000

using namespace std;


void koef(vector<int> &a,vector<int> &m,vector<int> x)
{
    for(int i=-len;i<len;i++)
    {
        for(int j=-len;j<len;j++)
        {
            if((x[1]*i-x[0]*j)!=0&&(x[1]*x[1]-x[0]*x[2])%(x[1]*i-x[0]*j)!=0)
            {
            if((x[2]*i-x[1]*j)%(x[1]*i-x[0]*j)==0&&((x[1]*x[1]-x[0]*x[2])%(x[1]*i-x[0]*j)==0))
            {
                if((x[2]*i-x[1]*j)/(x[1]*i-x[0]*j)>0&&(x[1]*x[1]-x[0]*x[2])/(x[1]*i-x[0]*j)>0)
                {

                    a.push_back((x[2]*i-x[1]*j)/(x[1]*i-x[0]*j));
                    m.push_back((x[1]*x[1]-x[0]*x[2])/(x[1]*i-x[0]*j));
                }
            }

        }}
    }
}


int main()
{
    int k;
    cin>>k;
    vector<int>numb;
    vector<int>x(3);
    int val=0;
    vector<int>a;
    vector<int>m;
    for(int i=0;i<k;i++)
    {
        cin>>val;
        numb.push_back(val);
    }
    for(int i=0;i<3;i++)
    {
        x.insert(x.end(),numb[i]-numb[i+1]);
    }
    for(int i=0;i<numb.size();i++)
    {
        cout<<numb[i]<<endl;
    }
    koef(a,m,x);
    for(int i=0;i<a.size();i++)
    {
        cout<<"a: "<<a[i]<<" "<<"m: "<<m[i]<<endl;
    }
    return 0;
}
