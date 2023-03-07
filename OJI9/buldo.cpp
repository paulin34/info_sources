#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("buldo.in");
ofstream fout("buldo.out");

int v[100001],n;

int check(int h)
{
    long long r = 0;
    bool ok = 1;
    for(int i = 1;i<=n;i++)
    {
        if(v[i] > h)
        {
            r += v[i]-h;
        }
        else if(v[i] < h)
        {
            r -= h - v[i];
            if(r<0)
            {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}
int main()
{
    fin >> n;
    int maxi = 0;
    for(int i =1;i<=n;i++)
    {
        fin >> v[i];
        maxi = max(maxi,v[i]);
    }
    int st = 1,dr = maxi+1;
    while(st<=dr)
    {
        int mij = (st + dr) / 2;
        if(check(mij))
        {
            st = mij + 1;
        }
        else dr = mij - 1;
    }
    fout << dr;
    return 0;
}








