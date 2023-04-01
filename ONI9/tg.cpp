#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("tg.in");
ofstream fout("tg.out");
int n,m,r;
int cdiv[4000001];
int gc()
{
    for(int i=2;i<=n;i++)
    {
        for(int j = i;j<i*i;j+=i)
        {
            cdiv[j]++;
        }
    }//2, 4, 8
}
int main()
{
    fin >> n;
    long long k=1;
    int cnt =0;
    gc();

    while((++k)<=n)
    {
        cnt+=cdiv[k*k];
    }

    fout << cnt;

}
//  36 6
//3 12
//2 18














