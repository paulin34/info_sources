#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("omogene.in");
ofstream fout("omogene.out");

int l,c;
int a[400][10001];
int z[400][10001];
int u[400][10001];

struct nod
{
    int d01,d12,d20;
};

bool cmp(nod x,nod y)
{
    return x.d01 < y.d01 ||
    (x.d01 == y.d01 && x.d12 < y.d12  || x.d01 == y.d01 && x.d12 == y.d12 && x.d20 < y.d20);
}
nod v[10001];
int main()
{
    fin >> l >> c;
    long long sol = 0;
    for(int i = 1;i<=l;i++)
    {
        for(int j = 1;j<=c;j++)
        {
            fin >> a[i][j];
        }
    }
    for(int i= 1;i<=l;i++)
    {
        for(int j = 1;j<=c;j++)
        {
            z[i][j] += z[i-1][j] + (a[i][j]==0);
            u[i][j] += u[i-1][j] + (a[i][j]==1);
        }
    }
    for(int k = 1;k<=l;k++)
    {
        for(int p = k;p<=l;p++)
        {
            int h = p-k+1;
            int st0 , st1 , st2;
            st0 = st1 = st2 = 0;
            v[0].d01 = v[0].d12 = v[0].d20 = 0;
            for(int j = 1;j<=c;j++)
            {
                int t0 = z[p][j] - z[k-1][j];
                st0 += t0;
                int t1 = u[p][j] - u[k-1][j];
                st1 += t1;
                int t2 = h-t0-t1;
                st2 += t2;
                v[j].d01 = st0 - st1;
                v[j].d12 = st1 - st2;
                v[j].d20 = st2 - st0;
            }
            sort(v,v+c+1,cmp);
            long long x = 1;
            for(int i = 1;i<=c;i++)
            {
                if(v[i-1].d01 == v[i].d01 && v[i-1].d12 == v[i].d12 && v[i-1].d20 == v[i].d20)x++;
                else
                {
                    sol += x * (x-1)/2;
                    x=1;
                }
            }
            sol += x * (x-1)/2;
        }
    }
    fout << sol;
    return 0;
}
