#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("compar.in");
ofstream fout("compar.out");
int n,c;
int v[100001];
int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    fin >> c >> n;
    if(c==1)
    {
        ///  14 23 17
        ///xa+r - xb-r= x(a-b)
        ///xb+r-xc-r = x(b-c)
        int mn = INT_MAX;
        for(int i = 1;i<=n;i++)
        {
            fin >> v[i];
            mn = min(mn,v[i]);
        }
        for(int i =1;i<=n;i++)v[i]-=mn;
        int x = 0;
        for(int i = 1;i<=n;i++)
        {
            if(v[i])
            {
                x = cmmdc(x,v[i]);
            }
        }
        fout << x;
    }
    else
    {
        /// 17   1 2 3 4 5 2

        while(n)
        {
            int x;
            fin >> x;
            if(x==1)
            {
                fout << "1 1"<<endl;
                n--;
                continue;
            }
            int y = 1;
            while(y*(y+1)/2 <= x)
            {
                y++;
            }
            y--;
            fout << y << " ";
            int t=1;
            int st=1,dr=y;
            while(st<=dr)
            {
                if(t==1)
                {
                    fout << t << " " << y+x-y*(y+1)/2 << " ";
                    t++;
                }
                else
                {
                    if(st==dr)
                    {
                        fout << st;
                        break;
                    }
                    fout << st << " " << dr << " ";
                }
                st++;
                dr--;
            }
            fout << endl;
            n--;
        }

    }
    return 0;
}















