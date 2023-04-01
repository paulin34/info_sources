#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("adlic.in");
ofstream fout("adlic.out");
int n,c;

int   v[1000001];
int cls[1000001];
int main()
{
    fin >> c >> n;
    if(c==1)
    {
        fin >> v[1];
        for(int i=2;i<=n;i++)
        {
            fin >> v[i];
            if(v[1]>v[i])
            {
                fout << v[i];
                return 0;
            }
        }
    }
    else
    {
        for(int i =1;i<=n;i++)fin >> v[i];
        
        int k = 1;
        cls[1]=v[1];
        for(int i =2;i<=n;i++)
        {
          
            if(v[i] < cls[k])
            {
                cls[++k] = v[i];
                continue;
            }

            int st = 1,dr = k;
            while(st<=dr)
            {
                int mij = (st+dr)/2;
                if(cls[mij] > v[i])st = mij+1;
                else dr = mij-1;
            }
            cls[st] = v[i];

        }
        fout << k;
    }
    ///8 7 4 4 2 1
}















