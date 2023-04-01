#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("sipet.in");
ofstream fout("sipet.out");

int n,p[4],r,A,B,C,R;

bool   bb[10000001];
struct pereche
{
    int a,b;
} v[10000001];

int prim(int x)
{
    int d=2;
    while(d*d<=x)
        if (x%d==0) return 0;
        else d++;
    return 1;
}

int main()
{
    int t;
    fin >> t;
    while(t)
    {
        fin >> n >> p[1];

        for ( int i = 2; i <= 3; ++ i )
            for ( p[i] = p[i - 1] + 1; !prim(p[i]); ++ p[i] );
        // a * p1 + b * p2 = n - c * p3 - r
        cout << p[2] << " " << p[3];
        for(int a = 0;a*p[1] <= n;a++)
        {
            for(int b = 0;b*p[2]+a*p[1] <= n && b < p[1];b++)
            {
                 int pos = a*p[1] + b * p[2];
                 v[pos].a = a;
                 v[pos].b = b;
                 bb[pos] = true;
            }
        }
        cout << "x";
        bool found = 0;
        R = -1;
        for(int r = 0;r<p[1] && R == -1;r++)
        {
            for(int c = 0;c*p[3]+r <= n && c <= p[1];c++)
            {
                int pos = c * p[3] + r;
                if(bb[n-pos] && (R==-1 || R!=-1 && A+B+C < v[n-pos].a + v[n-pos].b + c))
                {
                    found = 1;
                    A = v[n-pos].a;
                    B = v[n-pos].b;
                    C = c;
                    R = r;
                }
            }
        }
        for(int a = 0;a*p[1] <= n;a++)
        {
            for(int b = 0;b*p[2]+a*p[1] <= n && b < p[1];b++)
            {
                int pos = a *p[1] + b * p[2];
                 bb[pos] = 0;
            }
        }
        fout << A+B+C << " " << A << " " << B << " " << C << " " << R << endl;
        t--;
    }

    return 0;
}

/*

*/





