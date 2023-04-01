#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("dif2.in");
ofstream fout("dif2.out");

long long n,m,k,q,c,p1,p2;
long long x[300001];


long long grte(long long p)
{
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        int st=1,dr=n;
        while(st<=dr)
        {
            int mij=(st+dr)/2;
            if(x[mij] * x[i] <= p)st=mij+1;
            else dr=mij-1;
        }
        cnt+=dr;
    }
    return cnt;
}

long long get(long long pos)
{
    long long st=1,dr=x[n]*x[n];
    while(st<=dr)
    {
        long long mij = (st+dr)/2;
        if(grte(mij) <= n*n-pos)st=mij+1;
        else dr = mij-1;
    }
    return st;
}
int main()
{
    fin >> c >> n;
    if(c==1)
    {
        int mx=0,mn=INT_MAX;
        while(n--)
        {
            int x;
            fin >> x;
            mn = min(x,mn);
            mx = max(x,mx);
        }
        fout << 1ll * mx * mx - 1ll * mn*mn;
    }
    else
    {
        fin >> p1 >> p2;
        for(int i=1;i<=n;i++)fin>>x[i];
        sort(x+1,x+1+n);

        fout << get(p1)-get(p2);
    }

    return 0;
}
