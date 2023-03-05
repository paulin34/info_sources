#include <bits/stdc++.h>
#include <fstream>
#define ull unsigned long long int
using namespace std;
ifstream fin("compar.in");
ofstream fout("compar.out");

int n,v;

ull a[1500];
ull c[1500];
ull curge(ull x)
{
    ull jos = 0;
    a[1] = x;
    for(int i =1;i<=n-1;i++)
    {
        for(int j =1;j<=i;j++)
        {
            int pos = i*(i-1)/2+j;
            if(a[pos] < c[pos])return 0ull;
            a[pos] -= c[pos];
            a[i*(i+1)/2+j] += a[pos]/2 + a[pos]%2;
            a[i*(i+1)/2+j+1] += a[pos]/2;
            a[pos] = c[pos];
        }
    }

    int k = 0;
    for(int i =1;i<=n;i++)
    {
        int pos = n*(n-1)/2+i;
        if(a[pos] >= c[pos])jos += a[pos] - c[pos],k++;
    }
    if(k<n)jos =0ull;
    memset(a,0ull,sizeof(a));
    return jos;
}
int main()
{
    fin >> v >> n;
    int mx=0,k=0;
    for(int i =1;i<=n;i++)
    {
        int s =0;
        for(int j =1;j<=i;j++)
        {
            fin >> c[i*(i-1)/2+j];
            s+=c[i*(i-1)/2+j];
        }
        if(mx < s)
        {
            mx =s;
            k = i;
        }
    }
    if(v==1)
    {
        fout << k;
    }
    else
    {
        ull x=0;
        ull st = 0,dr = LLONG_MAX;
        while(st<=dr)
        {
            ull mij = (st+dr)/2;

            ull t = curge(mij);
            if(t==0)
            {
                st = mij+1;
            }
            else dr = mij - 1,x=t;
        }
        fout << st << " " << x;

    }
    return 0;
}

/*

    2        2
   4 2      3 2
  1 2 3        1


  2
  4 2
  1 2 3
  1 2 3 4
*/


