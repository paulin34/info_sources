#include <bits/stdc++.h>
#include <fstream>

using namespace std;
ifstream fin("arc.in");
ofstream fout("arc.out");

int n,v,m;
int c[10001];
int x[10001];
int maxim()
{
    int mx = 0,k=0;
    for(int i =1;i<=m;i++)
    {
        if(x[i]>mx)
        {
            mx = x[i];
            k = i;
        }
    }
    return k;
}
void elimina(int k)
{
    n-=x[k];
    int i = k-1,j=k+1;
    while(i>=1 && j <=m && c[i]==c[j] && x[i] + x[j] > 2)
    {
        n-=(x[i]+x[j]);
        i--;
        j++;
    }
    if(j>m)m=i;
    else
    {
        if(i>=1 && j <=m && c[i]==c[j])
        {
            x[i] += x[j];
            j++;
        }
        int t = m-j+i+1;
        i = i+1;
        while(j<=m)
        {
            x[i] = x[j];
            c[i] = c[j];
            j++;
            i++;
        }
        m = t;
    }
}
int main()
{
    fin >> v >> n;
    m =1;
    fin >> c[1];
    x[1]=1;
    for(int i = 2;i<=n;i++)
    {
        int k;
        fin >> k;
        if(k==c[m])x[m]++;
        else c[++m] = k,x[m]=1;
    }

    if(v==1)
    {
        fout << m;
        return 0;
    }

    int k = maxim();
    while(n>0 && x[k] > 2)
    {
        elimina(k);
        for(int i=1;i<=m;i++)
        {
            for(int j =1;j<=x[i];j++)cout << c[i] << " ";
        }
        cout << endl;
        if(k > 0)
        {
            k = maxim();
        }
    }
    if(n==0)fout << 0;
    else
    {
        fout << n << endl;
        for(int i =1;i<=m;i++)
        {
            for(int j = 1;j<=x[i];j++)fout << c[i] << endl;
        }
    }
    return 0;
}
///    5 1 3 3 2 2 2 2 3 1 1 5 6 4 4 4 4 7
/// c 5 1 3 2 3 1 5 6 4 7
/// x 1 1 2 4 1 2 1 1 4 7
/// x 2 1 4 7
