#include<bits/stdc++.h>
using namespace std;

class floyd {
    int n, a[10][10];
public:
    void read();
    void write();
    void dist();
};

void floyd::read() {
    int i,j;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the cost matrix: " << endl;
    for (i = 0; i < n; i++) 
        for(j = 0; j < n; j++) 
            cin >> a[i][j];
}

void floyd::dist() {
    int i,j,k;
    for(k = 0; k < n; k++)
        for(j = 0; j < n; j++) 
            for(i = 0; i < n; i++){
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
            }
}

void floyd::write() {
    int i,j;
    cout << "The distance matrix is shown below:" << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    floyd f;
    f.read();
    f.dist();
    f.write();
    return 0;
}