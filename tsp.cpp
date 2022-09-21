#include "bits/stdc++.h"
using namespace std;

int source;
class tsp
{
    int n, a[10][10], v[10];

public:
    int cost;
    void read();
    void minCost(int);
    int least(int);
    tsp()
    {
        cost = 0;
    }
};

void tsp::read()
{
    int i, j;
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter the cost matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        v[i] = 0;
    }
}

int tsp::least(int c)
{
    int i, nc = 999, min = 999;
    for (i = 0; i < n; i++)
    {
        if (a[c][i] != 0 && v[i] == 0)
        {
            if (a[c][i] <= min)
            {
                min = a[c][i];
                nc = i;
            }
        }
    }
    if (min != 999)
        cost += min;
    return nc;
}

void tsp::minCost(int city)
{
    int i, ncity;
    v[city] = 1;
    cout << city << " ";
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = source;
        cout << ncity << " ";
        cost += a[city][ncity];
        return;
    }
    minCost(ncity);
}

int main()
{
    int i, j;
    tsp t;
    t.read();
    cout << "Enter the source city : ";
    cin >> source;
    cout << "Sequence of the cities visited : " << endl;
    t.minCost(source);
    cout << endl;
    cout << "Cost of the treavel is :" << t.cost << endl;
    return 0;
}