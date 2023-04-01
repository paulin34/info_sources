#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("bazaf.in");
ofstream fout("bazaf.out");

long long  n,c,x;
long long f[101];
int p[21];

long long fp[1000001];
int main()
{
    fin >> c;
    f[1]=1;
    for(int i =2;i<=20;i++)
    {
        f[i] = i*f[i-1];
    }
    if(c==1)
    {

        fin >> n;
        int k =0;
        while(n)
        {
            long long x;
            for(int i =1;i<=20;i++)
            {
                if(f[i] <= n && f[i+1] > n)
                {
                     x=f[i],p[i]++;
                     break;
                }
            }
            //20
            // 14 8 2   0 1 6!*3
            n-=x;
        }

        for(int i =20;i>0;i--)
        {
            if(p[i])
            {
                if(!k)k= i;
                break;
            }
        }
        fout << k << " ";
        for(int i=1;i<=k;i++)fout << p[i] << " ";
    }
    else
    {

        /// 10*x + 5 * y   x=1 y=2
        /// 10*x + 5 *
        fin >> n;

        for(int i =1;i<=n;i++)
        {
            fin >> fp[i];
        }

        for(int i =1;i<=1000000;i++)
        {
            fp[i+1]+=fp[i]/(i+1);
            fp[i]=fp[i]%(i+1);
        }


        int k;
        for(int i=1000000;i>0;i--)
        {
            if(fp[i])
            {
                k=i;
                break;
            }
        }
        fout << k << " ";
        for(int i =1;i<=k;i++)fout << fp[i] << " ";


    }
}
/*
   // 1 1 1 1 1 1 1 0
*/

