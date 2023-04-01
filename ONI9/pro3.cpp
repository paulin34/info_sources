#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("pro3.in");
ofstream fout("pro3.out");

int c;
int a[4],r[4],n[4];
int main()
{

    for(int i =1;i<=3;i++)
    {
        fin >> a[i] >> r[i] >> n[i];
    }
    int i=1,j=1,k=1;
    long long x=a[1],y=a[2],z=a[3];
    int cnt = n[1]+n[2]+n[3];
    while(i<=n[1] && j <= n[2] && k <=n[3])
    {
        
        if(x==y)
        {
            if(y==z)
            {
                cnt--;
                if(r[3]>r[2])j++,y+=r[2];
                else k++,z+=r[3];
            }
            cnt--;
            if(r[2]>r[1])i++,x+=r[1];
            else j++,y+=r[2];
        }
        else if(y==z)
        {
            cnt--;
            if(r[3]>r[2])j++,y+=r[2];
            else k++,z+=r[3];
        }
        else if(z==x)
        {
            cnt--;
            if(r[3]>r[1])i++,x+=r[1];
            else k++,z+=r[3];
        }
        else
        {
            if(x<z && x < y)i++,x+=r[1];
            else if(y<z && y < x)j++,y+=r[2];
            else k++,z+=r[3];
        }

    }


    while(i<=n[1] && j<=n[2])
    {
        if(x==y)
        {
            cnt--;
            if(r[2]>r[1])i++,x+=r[1];
            else j++,y+=r[2];
        }
        else
        {
            if(x<y)i++,x+=r[1];
            else j++,y+=r[2];
        }
    }
    while(i<=n[1] && k<=n[3])
    {
        if(x==z)
        {
            cnt--;
            if(r[3]>r[1])i++,x+=r[1];
            else k++,z+=r[3];
        }
        else
        {
            if(x<z)i++,x+=r[1];
            else k++,z+=r[3];
        }
    }
    while(j<=n[2] && k<=n[3])
    {
        if(y==z)
        {
            cnt--;
            if(r[3]>r[2])j++,y+=r[2];
            else k++,z+=r[3];
        }
        else
        {
            if(y<z)i++,y+=r[2];
            else k++,z+=r[3];
        }
    }
    fout << cnt;

}
/*

P1 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
P2 = {3, 7, 11, 15, 19, 23, 27, 31}
P3 = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34}

*/

