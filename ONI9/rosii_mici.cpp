#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("rosii_mici.in");
ofstream fout("rosii_mici.out");

int t,n,m,q;
int a[1001][1001];
int h[1001];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    fin >> n >> m >> q;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)fin>>a[i][j];
    }

    while(q)
    {
        int x;
        fin >> x;
        for(int j =1;j<=m;j++)
        {
            int st=1,dr=n;
            while(st<=dr)
            {
                int mij = (st+dr)/2;
                if(a[mij][j] <= x)st=mij+1;
                else dr=mij-1;
            }
            h[j]=dr;
        }
        sort(h+1,h+m+1);
        long long amax = 0;
        for(int i =1;i<=m;i++)
        {
            if(amax < h[i]*(m-i+1))amax = h[i]*(m-i+1);
        }
        fout << amax << endl;
        q--;
    }
}
/*

1 9 6 2
1 10 10 4
7 15 10 6

3 2 1 0
*/

