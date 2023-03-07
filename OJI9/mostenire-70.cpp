#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#define ll long long int
using namespace std;

ifstream fin("compar.in");
ofstream fout("compar.out");

int n,k;
struct fiu
{
    int b,st,dr,ind;
} fii[100];

int v[1000001];
int check(int s)
{
    int parti = 0;
    int sc = 0;
    for(int x = 1;x<=n;x++)
    {
        sc += v[x];
        if(sc >= s)
        {
            parti++;
            sc =0;
            if(parti==k)return k;
        }
    }
    return parti;

}
bool cmpb(fiu x, fiu y)
{
    return x.b > y.b;
}
bool cmpi(fiu x,fiu y)
{
    return x.st < y.st;
}
void imparte(int smezin)
{
    int cnt = 0,last = 0;
    int s = 0;
    for(int i =1;i<=n;i++)
    {
        s += v[i];
        if(s>=smezin)
        {
            fii[++cnt].st = last+1;
            fii[cnt].dr = i;
            fii[cnt].b = s;
            if(cnt == k)
            {
                for(int j = i+1;j<=n;j++)fii[cnt].b += v[j];
                fii[cnt].dr = n;
                break;
            }
            last = i;
            s =0;
        }
    }
    sort(fii+1,fii+cnt+1,cmpb);
    for(int i =1;i<=n;i++)
    {
        fii[i].ind = i;
    }
    sort(fii+1,fii+cnt+1,cmpi);

}
/// 1 2 3 4 5 6 7 8
///
int main()
{
    fin >> n >> k;
    for(int i =1;i<=n;i++)
    {
        fin >> v[i];
    }
    int smezin;
    int st = 1,dr = INT_MAX;
    while(st<=dr)
    {
        int mij = (st+dr)/2;
        if(check(mij)==k)
        {
            st = mij+1;
        }
        else
        {
            dr = mij-1;
        }
    }
    smezin = dr;
    fout << smezin << endl;
    imparte(smezin);
    for(int i =1;i<=k;i++)
    {
        fout << fii[i].ind << " " << fii[i].dr - fii[i].st + 1 << "\n";
    }
    return 0;
}


