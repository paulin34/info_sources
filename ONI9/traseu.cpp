#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("traseu.in");
ofstream fout("traseu.out");

int n,m;
int dx[6] = {-1,0,0,0,0,1};
int dy[6] = {0,-1,0,0,1,0};
int dz[6] = {0,0,-1,1,0,0};
struct coordonate
{
    int x,y,z;
};

int a[105][105][105];
queue<coordonate> Q;
stack<coordonate> S;
coordonate c;

void bord()
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j =0;j<=n+1;j++)
        {
            a[0][i][j]=-1;
            a[n+1][i][j]=-1;
            a[i][0][j]=-1;
            a[i][n+1][j]=-1;
            a[i][j][n+1]=-1;
            a[i][j][0]=-1;
        }
    }
}

int main()
{



    fin >> n >> m;
    bord();

    int x,y,z;
    fin >> x >> y >> z;
    Q.push({x,y,z});
    a[x][y][z]=1;
    fin >> x >> y >> z;

    while(m)
    {
        fin >> c.x >> c.y >> c.z;
        a[c.x][c.y][c.z] = -1;
        m--;
    }

    while(!Q.empty())
    {
        coordonate x = Q.front();
        Q.pop();
        for(int i =0;i<6;i++)
        {
            coordonate v = {x.x + dx[i],x.y + dy[i],x.z + dz[i]};
            if(a[v.x][v.y][v.z]==0)
            {
                a[v.x][v.y][v.z]=a[x.x][x.y][x.z]+1;
                Q.push(v);
            }
        }
    }

    fout << a[x][y][z] << "\n";
;

    S.push({x,y,z});
    int l = a[x][y][z];
    while(l>1)
    {
        l--;
        coordonate x= S.top();
        for(int i =0;i<6;i++)
        {
            coordonate v = {x.x + dx[i],x.y + dy[i],x.z + dz[i]};
            if(a[v.x][v.y][v.z]==l)
            {
               S.push(v);
               break;
            }
        }
    }
    while(!S.empty())
    {
        fout << S.top().x << " " << S.top().y << " " << S.top().z << "\n";
        S.pop();
    }
}