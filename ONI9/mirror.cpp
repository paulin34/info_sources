#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("mirror.in");
ofstream fout("mirror.out");

int c,k,n;
bool bts[3200000];
bool bts2[100000][33];
int   bcnt[100000];

int f[100000];
bool bt[33];
int main()
{
    fin >> c >> n >> k;
    if(c==1)
    {
        int curr = 0;
        while(n)
        {
            int x;
            fin >> x;
            int ct =0;
            int i = curr;
            while(x)
            {
                bt[++ct] = x%2;
                x/=2;
            }
            for(int i = ct;i>0;i--)bts[++curr]=bt[i];
            n--;
        }
        for(int i=1;i<=curr;i++)cout<<bts[i];
        int i = 1;
        while(i<=curr-k+1)
        {
            int x = 0;
            int p =1;
            for(int j = i+k-1;j>=i;j--)
            {
                x += p*bts[j];
                p*=2;
            }
            fout << x << " ";
            i+=k;
        }
    }
    else
    {
        int curr = 0;
        int t =n;
        while(n)
        {
            int x;
            fin>>x;
            int cnt=0;

            while(x)
            {
                bts2[curr][cnt++]=x%2;
                f[curr]+=bts2[curr][cnt-1];
                x/=2;
            }
            bcnt[curr]=cnt-1;
            curr++;
            n--;
        }
        for(int i = 0;i<curr;i++)
        {
            for(int j = 1;j<=k&&f[i];j++)
            {
                for(int b =0;b<=bcnt[i];b++)
                {

                    bts2[i][b] = !bts2[i][b];
                    f[i]-=!bts2[i][b];
                    f[i]+= bts2[i][b];
                    if(!f[i])break;
                }
            }
        }
        for(int i = 0;i<curr;i++)
        {
            for(int j = 0;j<=32;j++)
            {
                cout << bts2[i][j];
            }
            cout << endl;
        }
        int lmax=0,s=0,e=0;
        for(int i = 0;i<=32;i++)
        {
            int l =0;
            int sus = 0;
            for(int j = 0;j<curr;j++)
            {
                if(bts2[j][i]==0)
                {
                    if(lmax<l || lmax==l && sus < s)
                    {
                        lmax = l;
                        s = sus;
                        e = j-1;
                    }
                    l=0;
                }
                else
                {
                    if(l==0)sus = j;
                    l++;
                }
            }
            if(lmax < l || lmax==l && sus < s)
            {
                lmax = l;
                s = sus;
                e = curr-1;
            }
        }
        fout << lmax << endl << s+1 << " " << e+1;
    }
    return 0;
}
/// 20 = 10100














