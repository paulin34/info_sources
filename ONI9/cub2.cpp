#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("cub2.in");
ofstream fout("cub2.out");
int n,c,p;

int a[201][201],b[201][201];
bool ciur[7000001];
void gc()
{
    ciur[1] = 1;
    for(int i =2;i*i<=7000000;i++)
    {
        if(!ciur[i])for(int j = i*i;j<=7000000;j+=i)ciur[j] = 1;
    }
}
int main()
{
    fin >> p >> n;
    if(p==1)
    {
        int x;
        fin >> x;
        int t = 0;
        while(t<x)
        {
            t+=n*n;
        }
        int h = t/(n*n);
        int i,j,d,sn;
        if(h%2==0)
        {
            i = 1,j=1,d=1,sn=1;
            while(t!=x)
            {

                if(d==1){j++;if(j==n)d=2;}
                else if(d==2){i++;if(i==n)d=3;}
                else if(d==3){j--;if(j==sn)d=4;}
                else {i--;if(i==sn+1)d=1,n--,sn++;}
                t--;

            }

        }
        else
        {
            i=1,j=1,d=1,sn=1;
            t-=n*n-1;
            while(t!=x)
            {

                if(d==1){j++;if(j==n)d=2;}
                else if(d==2){i++;if(i==n)d=3;}
                else if(d==3){j--;if(j==sn)d=4;}
                else {i--;if(i==sn+1)d=1,n--,sn++;}
                t++;

            }
        }
        fout << i << " " << j << " " << h;
    }
    else
    {
        gc();
        int t = 1;
        int i=1,j=1,d=1;
        bool ok = 1;
        while(!a[2][1])
        {
            a[i][j] = t;
            b[i][j] = 2*n*n+1-t;
            if(d==1)
            {
                j++;
                if(j==n)d=2;
            }
            else if(d==2)
            {
                i++;
                if(i==n)d=3;
            }
            else if(d==3)
            {
                j--;
                if(j==1)d=4;
            }
            else
            {
                i--;
            }
            t++;
        }
        int h = 1;
        int k1=0,k2=0,k3=0,k4=0;
        while(h<=n)
        {
            for(int j =1;j<=n;j++)
            {
                k1+=!ciur[a[1][j]];
                k2+=!ciur[a[j][n]];
                k3+=!ciur[a[n][j]];
                k4+=!ciur[a[j][1]];
            }
            for(int j =1;j<=n;j++)
            {
                a[1][j] += n*n*2;
                a[j][n] += n*n*2;
                a[n][j] += n*n*2;
                a[j][1] += n*n*2;
            }
            a[1][1] -= n*n*2;
            a[1][n] -= n*n*2;
            a[n][1] -= n*n*2;
            a[n][n] -= n*n*2;
            h+=2;
        }
        h=2;
        while(h<=n)
        {
            for(int j =1;j<=n;j++)
            {
                k1+=!ciur[b[1][j]];
                k2+=!ciur[b[j][n]];
                k3+=!ciur[b[n][j]];
                k4+=!ciur[b[j][1]];
            }
            for(int j =1;j<=n;j++)
            {
                b[1][j] += n*n*2;
                b[j][n] += n*n*2;
                b[n][j] += n*n*2;
                b[j][1] += n*n*2;
            }
            b[1][1] -= n*n*2;
            b[1][n] -= n*n*2;
            b[n][1] -= n*n*2;
            b[n][n] -= n*n*2;
            h+=2;
        }
        fout << k1 << endl << k2 << endl << k3 << endl << k4;
    }
}