#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("cufar.in");
ofstream fout("cufar.out");


int p,n;
int ciur[1000001];
int  cnt[1000001];


int main()
{
    int p,n;
    fin >> p >> n;


    if(p==1)
    {
        int x,k;
        fin >> x >> k;
        cnt[x] = k;
        for(int i =2 ;i<=1000000;i++)
        {
            if(!ciur[i])
            {
                for(int j = i;j<=1000000;j+=i)
                {
                    ciur[j]++;
                    if(ciur[j] == cnt[j] && j == x)
                    {
                        fout << i;
                        return 0;
                    }
                }
            }
        }
    }
    else
    {
        long long s = 0;
        for(int i=1;i<=n;i++)
        {
            int x,k;
            fin >> x >> k;
            cnt[x] = k;
        }
        for(int i =2 ;i<=1000000;i++)
        {
            if(!ciur[i])
            {
                for(int j = i;j<=1000000;j+=i)
                {
                    ciur[j]++;
                    if(ciur[j] == cnt[j])
                    {
                         s += i;
                    }
                }
            }
        }
        fout << s;
    }







    return 0;

}
