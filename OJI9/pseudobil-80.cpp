#include <bits/stdc++.h>
#include <fstream>

using namespace std;
ifstream fin("compar.in");
ofstream fout("compar.out");

int n,c,k,d;
int a[1501][1501];
int main()
{
    fin >> c >> n >> k >> d;
    if(c==1)
    {
        d--;
        fout << d*d/2+1;
    }
    else
    {
        while(k)
        {
            int x,y;
            fin >> x >> y;
            a[x][y] =1;
            k--;
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                a[i][j] += a[i][j-1];
            }
        }
        int q;
        fin >> q;
        while(q)
        {
            int x,y;
            fin >> x >> y;
            int cnt = 0;
            cnt += a[x+d/2][y+d/2] - a[x+d/2][y-d/2-1];
            for(int i =1;i<=d/2;i++)
            {
                int sus = a[x+i-1][y+i-1]-a[x+i-1][y-i];
                int jos = a[x+d-i+1][y+i-1] - a[x+d-i+1][y-i];
                cnt += sus+jos;
            }
            fout << cnt << endl;
            q--;
        }
    }
    return 0;
}

/*
    x x x y x x x
    x x x x x x x
    x x x x x x x
    y x x y x x y
    x x x x x x x
    x x x x x x x
    x x x y x x x
*/
