#include "bits/stdc++.h"
using namespace std;

class knapsack {
    int n, m, v[10][10], w[10], p[10];
public:
    void read();
    void sol();
    void write();
};

void knapsack::read() {
    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the weights of objects: " << endl;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cout << "Enter the profits of the objects: " << endl;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    cout << "Enter the capacity of the knapsack: " ;
    cin >> m;
}

void knapsack::write() {
    int i,j, x[10];
    cout  << "The output is " << endl;
    for(i = 0; i <= n; i++){
        for(j =   0; j <= m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The optimal solution is " << v[n][m] << endl;
    for(i=0; i<n; i++)
        x[i] = 0;
    i=n;
    j=m;
    while(i != 0 && j != 0){
        if(v[i][j] != v[i-1][j]){
            x[i] = 1;
            j = j- w[i];
        }
        i--;
    }
    for(i=0; i<n; i++)
        cout << "x[" << i << "] = " << x[i] << endl;
}

void knapsack::sol() {
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if(j < w[i])
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j], v[i-1][j-w[i]] + p[i]);
        }
    }
}

int main() {
    knapsack k;
    k.read();
    k.sol();
    k.write();
    return 0;
}