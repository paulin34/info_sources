


#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("defrag.out");
ifstream fin("defrag.in");

int n,c,p,s;

int disc[101][800];
int cnt[101];
int main()
{
    fin >> c >> p >> s;
    if(c==1)
    {
        int cl;
        fin >> cl;
        int klibere = 0;
        for(int i = 1;i <= cl;i++)
        {
            int x,y;
            fin >> x >> y;
            disc[x][y] = 1;
        }
        for(int i = 1;i<=p;i++)
        {
            int ok = 1;
            for(int j = 1;j<=s;j++)
            {
                if(disc[i][j])
                {
                    ok = 0;
                    break;
                }
            }
            klibere += ok;
        }
        fout << klibere;
    }
    else
    {
        int cl;
        fin >> cl;
        for(int i = 1;i <= cl;i++)
        {
            int x,y;
            fin >> x >> y;
            disc[x][y] = 1;
            disc[x][y+s] = 1;
            cnt[x]++;
            // 1 2 3 4 5 1 2 3 4 5
        }

        for(int i = 1;i <= p;i++)
        {
            int kmax = 0;
            for(int j = 1;j<= cnt[i];j++)
            {
                kmax += disc[i][j];
            }
            int k = kmax;
            for(int j = 2;j<=s;j++)
            {
                k+= disc[i][j+cnt[i]-1];
                k-= disc[i][j-1];
                if(k>kmax)kmax = k;
            }
            fout << cnt[i] - kmax << " ";
            // 1 2 3 4 5 1 2 3 4 5
        }
    }

    return 0;
}

