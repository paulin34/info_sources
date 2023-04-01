#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("arhipelag.in");
ofstream fout("arhipelag.out");

int c,m,n;
bool a[1001][1001];
bool a2[1001][1001];
int costx[1001];
int costy[1001];
int x1[1001],x2[1001];
int yu[1001],y2[1001];
struct ins
{
    int i1,i2,j1,j2;
} v[1000001];

int main()
{
    fin >> n >> m;
    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)fin>>a[i][j],a2[i][j]=a[i][j];
    }
    int cnt=0;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            if(a[i][j])
            {
                v[++cnt].i1 = i;
                v[cnt].j1 = j;
                v[cnt].i2 = i;
                v[cnt].j2 = j;
                a[i][j]=0;
                int x;
                for(x = i+1;x<=n && a[x][j];x++)
                {
                    v[cnt].i2=x;
                }
                for(x = j+1;x<=m && a[i][x];x++)
                {
                    v[cnt].j2=x;
                }
                for(x=i;x<=v[cnt].i2;x++)
                {
                    for(int y = j;y<=v[cnt].j2;y++)a[x][y]=0;
                }
            }
        }
    }
    for(int i =1;i<=cnt;i++)
    {
        x1[v[i].i1]++;
        x2[v[i].i2]++;
        yu[v[i].j1]++;
        y2[v[i].j2]++;
    }
    for(int i =1;i<=n;i++)x2[i]+=x2[i-1];
    for(int i =n-1;i>0;i--)x1[i]+=x1[i+1];
    for(int i=1;i<=m;i++)y2[i]+=y2[i-1];
    for(int i=m-1;i>0;i--)yu[i]+=yu[i+1];

    int dmin=INT_MAX,x,y;
    for(int i =1;i<=cnt;i++)
    {
        costx[1]+= max(max(1-v[i].i2,v[i].i1-1),0);
        costy[1]+= max(max(1-v[i].j2,v[i].j1-1),0);
    }

    for(int i =2;i<=n;i++)
    {
        costx[i]=costx[i-1]+x2[i-1]-x1[i];
    }
    for(int i =2;i<=m;i++)
    {
        costy[i]=costy[i-1]+y2[i-1]-yu[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            if(dmin>costx[i]+costy[j] && !a2[i][j])
            {
                dmin = costx[i]+costy[j];
                x=i;
                y=j;
            }
        }
    }
    fout << x << " " << y;
    return 0;
}
/// 20 = 10100














