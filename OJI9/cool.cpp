#include <bits/stdc++.h>
#include <fstream>

using namespace std;
ifstream fin("compar.in");
ofstream fout("compar.out");

int n,c,k;
int f[1001];
int v[5001];
bool f2[1001];
int main()
{
    fin >> c >> n >> k;
    if(c==1)
    {
        int maxi=0,mini = INT_MAX,ok=1,kdif=0;
        for(int i = 1;i<=k;i++)
        {
            int x;
            fin >> x;
            maxi = max(x,maxi);
            mini = min(x,mini);
            if(f[x])ok=0;
            f[x]++;
        }
        if(maxi-mini+1 == k && ok==1)fout << maxi;
        else
        {
            for(int i = 1;i<=1000;i++)kdif+=f[i]==1;
            fout << kdif;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)fin >> v[i];
        int lmax = 0,kmax=0;
        for(int i= 1;i<=n;i++)
        {
            int mini = INT_MAX;
            int maxi = 0;
            for(int j =i;j<=n;j++)
            {
                if(f2[v[j]])break;
                f2[v[j]]=1;
                maxi = max(maxi,v[j]);
                mini = min(mini,v[j]);
                if(maxi-mini == j-i)
                {
                    ///secventa cool
                    if(j-i+1 == lmax)kmax++;
                    else if(j-i+1 > lmax)lmax = j-i+1,kmax =1;
                }
            }
            memset(f2,0,sizeof(f2));
        }
        fout << lmax << "\n" << kmax;
    }

    return 0;
}
