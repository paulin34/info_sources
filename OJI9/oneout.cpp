#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("oneout.in");
ofstream fout("oneout.out");
int n,c;
bool ciur[1000001];
int v[1000001];
int secv[1000001][2];
int gc()
{
    for(int i = 2;i*i<=1000000;i++)
    {
        int pp = i * i;
        for(int j = pp;j<=1000000;j+=pp)ciur[j] = 1;
    }

}
int main()
{
    fin >> c >> n;
    if(c==1)
    {
        gc();

        int k = 0;
        for(int i = 1;i<=n;i++)
        {
            int x;
            fin >> x;
            if(ciur[x]==0)k++;
        }
        fout << k;
    }
    else
    {
        gc();
        for(int i = 1;i<=n;i++)fin >> v[i];
        int lmax = 0, k=0,st=0,last = 0,l=0;
        bool ok=0;
        for(int i = 1;i<=n;i++)
        {

            if(!ciur[v[i]])
            {
                if(!st)st = i;
                l++;
            }
            else
            {
                if(l==0)continue;
                if(ok==0)ok=1,last = i;
                else
                {

                    if(ciur[v[i-1]])
                    {
                        //cout << v[i-1] << " " << v[i] << endl;
                        st = 0;
                        l=0;
                        ok =0;
                        continue;
                    }
                    if(lmax == l)
                    {
                        secv[++k][0] = st;
                        secv[k][1] = i-1;
                    }
                    else if(lmax < l)
                    {
                        lmax = l;
                        k = 1;
                        secv[k][0] = st;
                        secv[k][1] = i-1;
                    }
                    st = 0;
                    l=0;
                    ok = 0;
                    i = last;
                }
            }


        }
        if(ok)
        {
            if(lmax == l)
            {
                secv[++k][0] = st;
                secv[k][1] = n;
            }
            else if(lmax < l)
            {
                lmax = l;
                k = 1;
                secv[k][0] = st;
                secv[k][1] = n;
            }
        }

        fout << lmax  << " " << k << endl;
        for(int i = 1;i<=k;i++)
        {
            fout << secv[i][0] << " " << secv[i][1] << endl;
        }
        ///3 10 5 8 9 11 4 15 21
        ///1 1  1 0 0 1  0 1  1
    }
    return 0;

}















