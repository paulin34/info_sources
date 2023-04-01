
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ofstream fout("harta.out");
ifstream fin("harta.in");

int p,n,m,k;

short int l[1010],a[1600][1600],scol[1600],slin[1600];

bool patrat(int i1,int j1,int i2,int j2)
{
    return i2-i1 == j2-j1;
}
int main()
{
    fin >> p;
    if(p==1)
    {
        fin >> n >> m >> k;
        int c = 0,lmax = 0;
        for(int i = 1;i<=k;i++)
        {
            int i1 , i2, j1 , j2;
            fin >> i1 >> j1 >> i2 >> j2;
            if(patrat(i1,j1,i2,j2))
            {
                lmax = max(lmax,i2-i1+1);
            }
            l[i] = max(i2-i1+1,j2-j1+1);
        }
        for(int i = 1;i<=k;i++)
        {
            if(l[i] <= lmax - 2)c++;
        }
        fout << lmax * lmax << " "  << c;
    }
    else
    {
        fin >> n >> m >> k;
        for(int i = 1;i<=k;i++)
        {
            int i1,j1,i2,j2;
            fin >> i1 >> j1 >> i2 >> j2;
            a[i1][j1]++;
            a[i2+1][j1]--;
            a[i1][j2+1]--;
            a[i2+1][j2+1]++;

            if(min(i2-i1+1,j2-j1+1) <= 2)continue;
            i1++,j1++,i2--,j2--;
            a[i1][j1]--;
            a[i2+1][j1]++;
            a[i1][j2+1]++;
            a[i2+1][j2+1]--;
        }

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                scol[j] += a[i][j];
                slin[i] += a[i][j];

                //cout << a[i][j] << " ";
            }
            //cout << endl;
        }
        slin[n+1] = 1;
        scol[m+1] = 1;

        for(int i = 1;i<=n;i++)
        {
            if(!slin[i])while(!slin[++i])slin[i] = -1;

        }
        for(int i = 1;i<=m;i++)
        {
            if(!scol[i])while(!scol[++i])scol[i] = - 1;
        }
        //for(int i = 1;i<=n;i++)cout << slin[i] << "  " ;
        //cout << endl;
        //for(int i = 1;i<=m;i++)cout << scol[i] << "  " ;
        //cout << endl;
        for(int i = 1;i<=n;i++)
        {
            if(slin[i] == -1)continue;
            for(int j = 1;j<=m;j++)
            {
                if(scol[j]!=-1)fout << a[i][j] << " ";
            }
            fout << endl;
        }
    }
    return 0;
}

// 4 : 1 4
// 9 :
