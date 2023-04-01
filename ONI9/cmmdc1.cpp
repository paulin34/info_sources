#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("cmmdc1.in");
ofstream fout("cmmdc1.out");
int n,m,k,q;
int v[1000001];

int main()
{
   int x=1,mx=0;//cmmdc
   fin >> n >> k;
   for(int i =1;i<=n;i++)
   {
       int x;
       fin >> x;
       v[x]++;
   }


   for(int i =2;i<=1000000;i++)
   {
       int cnt=0;
       for(int j = i;j<=1000000;j+=i)
       {
           cnt += v[j];
           if(cnt >= k)
           {
               x=i;
               break;
           }

       }

   }
   fout << x << endl;
   for(int i =1000000;i>0;i--)
   {
       if(v[i] && i % x ==0 && k)
       {
           while(v[i] && k)
           {
               fout << i << " ";
               v[i]--;
               k--;
           }
       }
   }

}















