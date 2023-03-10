#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#define ll long long int
using namespace std;

ifstream fin("pergament.in");
ofstream fout("pergament.out");

int n,k,q;
int a,b,c,d,x,y;

struct sv
{
    int j,s,t;
} col[200001];

int sp[52];
bool cmp(sv x,sv y)
{
    return x.j < y.j;
}
int main()
{
    fin >> n >> k >> q;
    fin >> a >> b >> c >> d;
    fin >> x >> y;
    int res = 0;
    int m = 0;
    while(q)
    {
        int j,r,l;
        fin >> j >> r >> l;
        col[++m] = {r,j,1};
        col[++m] = {r+l,j,-1};
        q--;
    }
    sort(col+1,col+m+1,cmp);

    int j =1;

    for(int i =1;i<=n;i++)
    {
        while(col[j].j <= i && j<=m)
        {
            for(int l = col[j].s;l<=k;l++)
            {
                sp[l]+=col[j].t;
            }
            j++;
        }
        res += sp[x+y-1]-sp[x-1];
        x = 1 + (x * a + b)%k;
        y = 1 + (y*c+d)%(k-x+1);
    }
    fout << res;
    return 0;
}








