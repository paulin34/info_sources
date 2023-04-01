#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("comun.in");
ofstream fout("comun.out");

int c,n,b;
int v[100001];
bool f[100001];

int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a =b;
        b=r;
    }
    return a;
}
int main()
{
    fin >> n;
    for(int i=1;i<=n;i++)fin>>v[i],f[v[i]]=1;
    for(int i =1;i<=100000;i++)
    {
        if(!f[i])continue;
        int gcd=0;
        for(int j = i+i;j<=100000;j+=i)
        {
            if(!f[j])continue;
            gcd = cmmdc(gcd,j);
        }
        if(gcd == i)f[i]=0;
    }
    int k =0;
    for(int i =1;i<=100000;i++)if(f[i])k++;
    fout << k << endl;
    for(int i =1;i<=100000;i++)if(f[i])fout << i << " ";

}


