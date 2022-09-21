#include<bits/stdc++.h>
using namespace std;

class warshall {
    int n, a[10][10];
public:
    void read();
    void path();
    void write();
};

void warshall::read() {
    int i, j;
    cout << "Enter number of nodes: " ;
    cin >> n;
    cout << "Enter adjacency matrix: " << endl;
    for (i = 0; i < n; i++) 
        for(j = 0; j < n; j++)
            cin >> a[i][j];
}

void warshall::path() {
    int i,j,k;
    for(k = 0; k < n; k++) 
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++){
                if(a[i][k] == 1 && a[j][k] == 1){
                    a[i][j] = 1;
                }
            }
}

void warshall::write() {
    int i,j;
    cout << "Transitive closure is: " << endl;
    for(i=0; i< n; i++){
        for(j=0; j< n; j++){
            cout << a[i][j] << " " ;
        }
        cout << "\n";
    }
}

int main() {
    warshall w;
    w.read();
    w.path();
    w.write();
    return 0;
}