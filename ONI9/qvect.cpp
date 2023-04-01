#include <bits/stdc++.h>
#include <fstream>
#include <cstring>

using namespace std;

ofstream fout("qvect.out");
ifstream fin("qvect.in");

int n,t,q;
int v[101][5001],ic[10002],l[101];
bool id[10002];
void solve1()
{
    int a,b;
    fin >> a >> b;
    int i=1,j=1,k=0;
    while(i<=l[a] && j<=l[b])
    {
        if(v[a][i] < v[b][j])ic[++k]=v[a][i++],id[k]=0;
        else ic[++k] = v[b][j++],id[k]=1;
    }
    while(i<=l[a])ic[++k]=v[a][i++],id[k]=0;
    while(j<=l[b])ic[++k]=v[b][j++],id[k]=1;

    int difmin = INT_MAX;
    int x=1;


    while(x<=k-1)
    {
        while(id[x]==id[x+1] && x<=k-1)x++;
        if(x>k-1)break;
        difmin=min(ic[x+1]-ic[x],difmin);
        x++;
    }
    fout << difmin << endl;

}

int grt(int x, int i)
{
    int st=1,dr=l[i];
    while(st<=dr)
    {
        int mij = (st+dr)/2;
        if(v[i][mij] <= x)st = mij+1;
        else dr = mij-1;
    }
    return dr;
}

void solve2()
{
    int a,b,k=0;
    fin >> a >> b;
    for(int i =a;i<=b;i++)k+=l[i];

    int st=-1000000001,dr=1000000001;
    while(st <=dr)
    {
        int mij = (st+dr)/2;
        int tot = 0;
        for(int i =a;i<=b;i++)tot+=grt(mij,i);

        if(tot < k/2)st=mij+1;
        else dr=mij-1;
    }
    fout << st << endl;
}
int main()
{
    fin >> n >> q;
    for(int i =1;i<=n;i++)
    {
        int k;
        fin >> k;
        for(int j =1;j<=k;j++)fin >> v[i][j];
        l[i]=k;
    }

    while(q)
    {
        fin >> t;
        if(t==1)solve1();
        else solve2();
        q--;
    }
    return 0;
}

