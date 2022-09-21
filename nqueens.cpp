#include "bits/stdc++.h"
using namespace std;

class nqueens
{
public:
    void print(int n, int x[]);
    int place(int x[], int k);
    void nq(int n);
};

void nqueens::print(int n, int x[])
{
    int i, j;
    char c[10][10];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c[i][j] = '*';

    for (i = 1; i <= n; i++)
        c[i][x[i]] = 'Q';

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int nqueens::place(int x[], int k)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == x[k] || i - x[i] == k - x[k] || i + x[i] == k + x[k])
        {
            return 0;
        }
    }
    return 1;
}

void nqueens::nq(int n)
{
    int x[10];
    int c = 0;
    int k = 1;
    x[k] = 0;
    while (k != 0)
    {
        x[k] += 1;
        while ((x[k] <= n) && (!place(x, k)))
            x[k] += 1;
        if (x[k] <= n)
        {
            if (k == n)
            {
                c++;
                cout << "Solution " << c << " is " << endl;
                print(n, x);
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int n;
    nqueens q;
    cout << "Enter number of queens: ";
    cin >> n;
    q.nq(n);
    return 0;
}