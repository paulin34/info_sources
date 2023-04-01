#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("livada1.in");
ofstream fout("livada1.out");
int n,m,r;
long long c,x,y,z,w,u;
int a[101][25001];
long long sp[101][25001];
int mxp[101][25001];
long long v[101];
bool cmp(long long a,long long b)
{
    return a > b;
}
int main()
{
   fin >> n >> m >> c >> r;
   fin >> x >> y >> z >> w >> u;
   for(int i =1;i<=m;i++)fin >> a[1][i];
   for(int i =2;i<=n;i++)fin >> a[i][1];
   for(int i = 2;i<=n;i++)
   {
        for(int j =2;j<=m;j++)
        {
            a[i][j]=(x*a[i-1][j] + y *a[i][j-1] + z * a[i-1][j-1]+w )%u;
        }
   }
   for(int i =1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)sp[i][j]=a[i][j]+sp[i][j-1],mxp[i][j]=max(a[i][j],mxp[i][j-1]);

   }


   int st = 1,dr = u-1;
   while(st<=dr)
   {
       int mij = (st+dr)/2;
       long long s =0;

       for(int i= 1;i<=n;i++)
       {
           int st2=1,dr2=m;
           while(st2<=dr2)
           {
               int mij2 = (st2+dr2)/2;

               if(mxp[i][mij2]>mij)dr2 = mij2-1;
               else st2 = mij2+1;
           }
           v[i]=sp[i][dr2];

       }

       sort(v+1,v+n+1,cmp);
       for(int j=1;j<=r;j++)
       {
           s+=v[j];

       }
       if(s>=c)
       {
           dr = mij-1;
       }
       else st = mij+1;
       memset(v,0,sizeof(v));
   }
   fout << st << " " ;

}















