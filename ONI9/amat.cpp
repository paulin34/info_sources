#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("amat.in");
ofstream fout("amat.out");

int c,n,m;
int a[1005][1005];
int mars[1005][1005];
struct u{
    int i1,j1,i2,j2,v;
} v[100001];
int main()
{
    fin >> c;
    fin >> n >> m;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)fin>>a[i][j];
    }
    if(c==1)
    {
        int amax=0,emax=0;
        int i1,i2,j1,j2;
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                if(a[i][j])
                {
                    int x,y;
                    int l =0,l1=0;
                    for(x=j;x<=m;x++)
                    {
                        if(a[i][j] == a[i][x])l++;
                        else break;
                    }
                    if(a[i][j] != a[i][x])x--;

                    for(y=i;y<=n;y++)
                    {
                        if(a[i][j]==a[y][j])l1++;
                        else break;
                    }

                    if(a[y][j] != a[i][j])y--;
                    int ar=l1*l;

                    if(ar==amax && a[i][j]>emax || (ar>amax))
                    {
                        amax =ar;
                        emax = a[i][j];
                        i1=i,j1=j,i2=y,j2=x;
                    }

                    for(int yy = i;yy<=y;yy++)
                    {
                        for(int xx = j;xx<=x;xx++)
                        {
                            a[yy][xx]=0;
                        }
                    }

                }
            }
        }
        fout << i1 << " " << j1 << " " << i2 << " " << j2;
    }
    else
    {
        int q,k;
        fin >> q >> k;
        for(int i =1;i<=q;i++)
        {
            fin >> v[i].i1 >> v[i].j1 >> v[i].i2 >> v[i].j2 >> v[i].v;
        }
        int st=1,dr=q;
        while(st<=dr)
        {
            int mij = (st+dr)/2;
            for(int i =1;i<=mij;i++)
            {

                mars[v[i].i1][v[i].j1] += v[i].v;
                mars[v[i].i2+1][v[i].j2+1] += v[i].v;
                mars[v[i].i1][v[i].j2+1] -= v[i].v;
                mars[v[i].i2+1][v[i].j1] -= v[i].v;
            }
            int vmin = INT_MAX;
            for(int i =1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)mars[i][j] += mars[i-1][j]
                                                + mars[i][j-1] - mars[i-1][j-1];

            }
            for(int i =1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)vmin = min(a[i][j] + mars[i][j],vmin),mars[i][j]=0;
            }
            if(vmin >= k)dr = mij-1;
            else st = mij+1;

        }
        fout << st;
    }
}














;
