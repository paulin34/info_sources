#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#define ll long long int
using namespace std;

ifstream fin("compar.in");
ofstream fout("compar.out");

int n,c;
int v[100001];
int f[10];
int main()
{
    fin >> c >> n;
    for(int i =1;i<=n;i++)
    {
        fin >> v[i];
    }
    if(c==1)
    {
        int tot1 = 1,tot2=0;
        for(int i =2;i<=n;i++)
        {
            if(v[i]==v[i-1])continue;
            tot1++;
        }
        for(int i =2;i<=n;i++)
        {
            if(v[i]==v[i-1])
            {
                tot2++;
                while(v[i]==v[i-1] && i <=n)
                {
                    i++;
                }
            }
        }
        fout << tot1 << endl << tot2;
    }
    else
    {
        int fpar=0,fimpar=0;
        for(int i =1;i<=n;i++)
        {
            f[v[i]]++;
        }
        for(int i =0;i<=9;i++)
        {
            if(!f[i])continue;
            if(f[i]%2==0)fpar++;
            else fimpar++;

        }

        if(!fimpar)
        {
            for(int i = 9;i>=0;i--)
            {
                if(f[i])
                {
                   for(int j=1;j<=f[i]/2;j++)fout<< i;
                }
            }
            for(int i=0;i<=9;i++)
            {
                if(f[i])
                {
                    for(int j =1;j<=f[i]/2;j++)fout << i;
                }
            }

        }
        ///2 4 7 8 1 8 7 4 2 1
        /// 8 7 4 2 1 1 2 4 7 8
        else if(fimpar==1)
        {
            int fmin = 10,ci;
            int first = 1;
            for(int i= 0;i<=9;i++)
            {
                if(f[i]%2==1)fmin = f[i],ci=i;
            }
            for(int i = 9;i>=0;i--)
            {
                if(first && f[i] && i==0)continue;
                if(fmin == 1 && f[i]%2==1)continue;
                for(int j =1;j<=f[i]/2+f[i]%2;j++)fout << i;
                if(f[i])first = 0;
            }
            if(fmin==1)fout<<ci;
            for(int i = 0;i<=9;i++)
            {
                if(first && f[i] && i ==0)continue;
                if(fmin == 1 && f[i]%2==1)continue;
                for(int j=1;j<=f[i]/2;j++)fout << i;
            }

        }
        else
        {
            int cmx=-1;
            int cmx2=-1;
            for(int i=9;i>=0;i--)
            {
                if(f[i] % 2)
                {
                    if(i>cmx)cmx=i;
                    else if(i>cmx2)cmx2=i;
                }
            }
            cout << cmx <<  " " << cmx2;
            bool first = 1;
            if(f[cmx]==1)
            {
                cout << "X";
                for(int i = 9;i>=0;i--)
                {
                    if(f[i]&&i==0&&first)continue;
                    if(i==cmx)continue;
                    for(int j =1;j<=f[i]/2;j++)fout<<i;
                    if(f[i]/2)first = 0;

                }
                for(int i =1;i<=f[cmx];i++)fout<<cmx;
                for(int i = 0;i<=9;i++)
                {
                    if(f[i]&&i==0&&first)continue;
                    if(i==cmx)continue;
                    for(int j =1;j<=f[i]/2;j++)fout<<i;
                }
            }
            else
            {
                int cmin = -1;
                for(int i = 9;i>=0;i--)
                {
                    if(f[i]&&i==0&&first)continue;
                    for(int j =1;j<=f[i]/2+(i==cmx);j++)fout<<i,cmin=i;
                    if(f[i]/2+(i==cmx))first = 0;

                }
                if(cmin!=-1)fout << cmin;
                for(int i = 0;i<=9;i++)
                {
                    if(f[i]&&i==0&&first)continue;
                    for(int j =1;j<=f[i]/2;j++)fout<<i;
                }
            }
        }
        /// 1 1 2 2 2 5 5 5 3
        /// 5 5 2 1 1 2 5
        /// 1 1 2 5 3



    }
    return 0;
}






