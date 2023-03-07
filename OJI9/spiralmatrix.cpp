#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#define ull unsigned long long
using namespace std;

ifstream fin("spiralmatrix.in");
ofstream fout("spiralmatrix.out");



int main()
{
    ull  n;
    fin >> n;
    ull a = n*n/ (1LL * 2);
    ull b = a+1+n%2;
    ull x[2] = {a,b};
    // n impar

    ull t = n;
    ull i=1,j=1,v=1;

    for(int k = 0;k<2;k++)
    {
        a = x[k];
        ull t = n;
        ull i=1,j=1,v=1;
        while(t > 1)
        {
            ull vn = v + 2*(t+t-2);
            if(vn <= a)
            {
                v = vn;
                i++;
                j++;
                t-=2;
            }
            else break;
        }


        if(v+t-1 >= a)
        {
            j = j+a-v;
        }
        else if(v+t+t-2 >= a)
        {
            j = j+t-1;
            i = i+a-(v+t-1);
        }
        else if(v+t+t+t-3 > a)
        {
            i = i+t-1;
            j = j+v+t+t+t-3 - a;
        }
        else
        {
            i = i+v+4*t-5-a+1;
        }
        fout << i << " " << j << endl;
    }


    return 0;
}








