#include <bits/stdc++.h>
#include <fstream>
#include <cstring>

using namespace std;

ofstream fout("secvente.out");
ifstream fin("secvente.in");

int n;
int v[200001];
int pos[1000001];

int main()
{
    fin >> n;
    for(int i = 1;i<=n;i++)
    {
        fin >> v[i];
    }
    int best = 0;
    for(int i = 1;i<=n;i++)
    {
        int beg = v[i];
        int en = v[i];
        if(pos[v[i]-1])beg = pos[v[i]-1];
        if(pos[v[i] + 1])en = pos[v[i]+1];

        pos[beg] = en;
        pos[en] = beg;



        best = max(best, en-beg+1);
        fout << best << endl;
    }


    return 0;
}

