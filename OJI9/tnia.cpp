#include <bits/stdc++.h>
#include <fstream>
#define ll long long int
using namespace std;

ifstream fin("tnia.in");
ofstream fout("tnia.out");

int n,m,v;

int h[100001];
ll sp[100001];
int main()
{
    fin >> n >> m;
    for(int i =1;i<=n;i++)fin >> h[i],sp[i] = h[i] + sp[i-1];
    int q;
    fin >> q;
    while(q)
    {
        int a,b,c,d;
        fin >> a >> b >> c >> d;
        ll s = 0;
        int st=a,dr=c;
        while(st<=dr)
        {
            int mij = (st+dr)/2;
            if(h[mij] < b)
            {
                st = mij + 1;
            }
            else dr = mij - 1;
        }
        int St = st;
        dr = c;
        while(st<=dr)
        {
            int mij = (st+dr)/2;
            if(h[mij] >= d)
            {
                dr = mij-1;
            }
            else st = mij + 1;
        }

        s+= (c-dr) * (d-b+1);
        s+=(sp[dr]-sp[St-1])-(dr-St+1)*(b-1);
        fout << s << endl;
        q--;
    }
    return 0;
}
/*

1 1 1 1 1
1 1 1 1 1
0 1 1 1 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
0 0 0 1 1
0 0 0 0 1
0 0 0 0 1




*/








