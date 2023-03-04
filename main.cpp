#include <fstream>
#include <algorithm>
using namespace std;

ofstream fout("betasah.out");
ifstream fin("betasah.in");

short int a[2010][2010],n,k,d;
int palbe[1001], dame[101][2];

int main()
{
    fin >> n >> d >> k;
    int pmax = 0;
    for(int i = 1;i<=n;i++)
    {
        palbe[i] = i;
    }
    for(int i = 1;i<=d;i++)
    {
        int l,c;
        fin >> l >> c;
        a[l][c] = 1;
        dame[i][0] = l,dame[i][1] = c;
    }
    for(int i = 0;i<=n+1;i++)
    {
        a[i][i+1] = 2;
        a[i][i+2] = 2;
        a[n+1][i] = 2;
        a[0][i] = 2;
        a[i][0] = 2;
    }
    for(int i = 1;i<=k;i++)
    {
        int l,c;
        fin >> l >> c;
        palbe[l]--;
        a[l][c] = 2;
    }
    for(int i = 1;i<=n;i++)pmax = max(palbe[i],pmax);

    fout << pmax << endl;

    for(int i = 0;i<=n+1;i++)
    {
        //for(int j = 0;j<=n+1;j++)cout << a[i][j] << " ";
        //cout << endl;
    }
    for(int i = 1;i<=d;i++)
    {
        int l = dame[i][0], c = dame[i][1];
        int l1 = l - 1, c1 = c;
        //sus
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            l1--;
        }
        //jos
        l1 = l+1,c1 = c;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            l1++;
        }
        // stanga
        l1 = l,c1 = c-1;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            c1--;
        }
        //dreapta
        l1 = l,c1 = c+1;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            c1++;
        }
        //st sus
        l1 = l-1,c1 = c-1;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            c1--;
            l1--;
        }
        //dr sus
        l1 = l-1,c1 = c+1;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            c1++;
            l1--;
        }
         //st jos
        l1 = l+1,c1 = c-1;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            c1--;
            l1++;
        }
         //dr jos
        l1 = l+1,c1 = c+1;
        while(a[l1][c1] != 2 && a[l1][c1] != 1)
        {
            a[l1][c1] = 3;
            c1++;
            l1++;
        }
    }

    int p = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)if(a[i][j] == 3)p++;
    }
    fout << p;
    return 0;
}
