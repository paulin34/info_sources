#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("lenes.in");
ofstream fout("lenes.out");

int n,m,k1,k2,p;
int a[505][505],aux[505];
int sp[505][505];
int min3(int x,int y,int z)
{
    return min(min(x,y),z);
}
int cmin(int c,int k,int r)
{
    int i=1,j=1;//i st j dr
    if(c==1)i=n+1;
    if(c==m)j=n+1;
    if(r==-1)i=n+1;
    if(r==1)j=n+1;

    int tot=0;
    tot+=sp[c][n];

    while(k && i<=n && j<=n)
    {
        if(a[c-1][i] < a[c+1][j])tot+=a[c-1][i],i++;
        else tot+=a[c+1][j],j++;
        k--;
    }
    while(i<=n && k)
    {
        tot+=a[c-1][i++];
        k--;
    }
    while(j<=n && k)
    {
        tot+=a[c+1][j++];
        k--;
    }
    return tot;
}

int caz1(int i,int j)
{
    return cmin(i,k1,0)+cmin(j,k2,0);
}
int caz2(int i,int j)
{
    if(i==1 && k1!=0)return INT_MAX;
    if(j==m && k2!=0)return INT_MAX;

    return cmin(i,k1,1)+cmin(j,k2,-1);
}
int caz3(int l,int r)
{
    int ku=k1,kd=k2;

    int i=1,k=1,j=1;
    if(l==1)i=n+1;
    if(r==m)j=n+1;
    if(i==n+1 && j==n+1)
    {
        if(k1+k2>m)return INT_MAX;
        return sp[l][n]+sp[r][n]+sp[l+1][k1+k2];
    }

    int tot =0;
    int mid = l+1;
    tot+=sp[l][n]+sp[r][n]+sp[l-1][k1]+sp[r+1][k2];
    if(j==n+1)
    {

        tot+=sp[mid][k2];

        k=k2+1,i=k1;
        while(k<=n && i)
        {
            if(a[mid][k] < a[l-1][i])
            {
                tot-=a[l-1][i--];
                tot+=a[mid][k++];
            }
            else break;
        }
        return tot;
    }
    if(i==n+1)
    {
        tot+=sp[mid][k1];
        k=k1+1,j=k2;
        while(j && k<=n)
        {
            if(a[mid][k] < a[r+1][j])
            {
                tot-=a[r+1][j--];
                tot+=a[mid][k++];
            }
            else break;
        }
        return tot;
    }

    i=k1,j=k2;
    while(i && j && k<=n)
    {
        if(a[mid][k] < a[l-1][i] && a[mid][k] < a[r+1][j])
        {
            if(a[l-1][i] > a[r+1][j])
            {
                tot-=a[l-1][i--];
                tot+=a[mid][k++];
            }
            else
            {
                tot-=a[r+1][j--];
                tot+=a[mid][k++];
            }
        }
        else if(a[mid][k] < a[r+1][j])
        {
            tot-=a[l-1][i--];
            tot+=a[mid][k++];
        }
        else if(a[mid][k] < a[r+1][j])
        {
            tot-=a[r+1][j--];
            tot+=a[mid][k++];
        }
        else break;
    }
    while(i && k<=n)
    {
        if(a[mid][k] < a[l-1][i])
        {
            tot-=a[l-1][i--];
            tot+=a[mid][k++];
        }
        else break;
    }
    while(j && k<=n)
    {
        if(a[mid][k] < a[r+1][j])
        {
            tot-=a[r+1][j--];
            tot+=a[mid][k++];
        }
        else break;
    }
    return tot;
}
/*

99 1 33 9 2 4 7
99 1 44 8 1 2 3
98 1 55 8 2 3 2
97 1 66 4 3 2 1
29 +11=40+3+5=48
198+8+2+7=215
*/
int main()
{
    fin >> p;
    fin >> n >> m >> k1 >> k2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fin >> a[j][i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        sort(a[i]+1,a[i]+1+n);
        for(int j=1;j<=n;j++)
        {
                sp[i][j]+=sp[i][j-1]+a[i][j];
        }
    }

    if(p==1)
    {
        int mn=INT_MAX;
        for(int i=1;i<=m;i++)
        {
            mn = min(cmin(i,k1,0),mn);
        }
        fout << mn;
    }
    else
    {
        int mn = INT_MAX;

        //cout << caz3(3,5);
        for(int i =1;i<=m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                int t=INT_MAX;
                if(j-i>=3)t=caz1(i,j);
                else if(j-i==1)t=caz2(i,j);
                else if(j-i==2)t=caz3(i,j);
                //if(t!=INT_MAX)cout << t << " ";
                mn = min(t,mn);
            }
        }
        swap(k1,k2);
        for(int i =1;i<=m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                int t=INT_MAX;
                if(j-i>=3)t=caz1(i,j);
                else if(j-i==1)t=caz2(i,j);
                else if(j-i==2)t=caz3(i,j);
                //if(t!=INT_MAX)cout << t << " ";
                mn = min(t,mn);
            }
        }
        fout << mn;

    }

}
