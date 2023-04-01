#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("risc.in");
ofstream fout("risc.out");

int n,p;
int v[100001];

int vSt[100001];
int vDr[100001],vDr2[100001];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    fin >> p >> n;
    if(p==1)
    {
        int imax = 0, vmax =0;
        for(int i = 1;i<=n;i++)
        {
            fin >> v[i];
            if(vmax < v[i])
            {
                vmax = v[i];
                imax = i;
            }
        }
        int ok = 1;
        int max2 = 0;
        for(int i = 1;i<imax;i++)
        {
            max2 = max(v[i],max2);
        }
        for(int i = imax+1;i<=n;i++)
        {
            if(v[i] <= max2)ok = 0;
        }
        if(!ok)
        {
            fout << -1;
        }
        else fout << imax;

    }
    else
    {
        int imax = 0,vmax = 0;
        for(int i =1;i<=n;i++)
        {
            fin >> v[i];
            if(vmax < v[i])
            {
                vmax = v[i];
                imax = i;
            }
        }
        long long  sol = 0;
        int mindr = 100001,kDr =n-imax,kSt=0;
        for(int i = imax+1;i<=n;i++)mindr = min(v[i],mindr),vDr[i-imax]=v[i];
        for(int i = 1;i<imax;i++)
        {

            if(v[i] > mindr)
            {
                vDr[++kDr] = v[i];
                v[i] = 0;
                sol++;
            }
            else
            {
                vSt[++kSt] = v[i];
            }
        }


        for(int i = 1;i<=kSt;i++)
        {
            if(vSt[i] < vSt[i-1])
            {
                vDr[++kDr] = vSt[i-1];
                vSt[i-1] = 0;
                sol++;
            }
        }
        for(int i = 1;i<=kDr;i++)vDr2[i] = vDr[i];

        int d = 0;
        sort(vDr2+1,vDr2+1+kDr,cmp);
        for(int i = 1;i<=kDr;i++)
        {
            if(vDr[i] != vDr2[i-d])
            {
                d++;
            }
        }
        fout << sol+d;
    }

    // 25 3 7 10 19 30
    // 3 7 10 19  30  25
    // 2 8 4 20 16 3       2 0 0 20 16 3 4 8
                                                // 3 8 4 16
                                                // 16 8 4 3

    return 0;
}









