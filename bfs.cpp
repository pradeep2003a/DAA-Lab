#include<bits/stdc++.h>
using namespace std;


class bfs {
    int a[10][10], s[10], source, n;
public:
    void read();
    void BFS();
    void write();
};

void bfs::read() {
    int i, j;
    cout << "Enter the number of nodes: " ;
    cin >> n;
    cout << "Enter adjacency matrix: " << endl;
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter the source node: ";
    cin >> source;
}

void bfs::BFS() {
    int i, u, v, f, r, q[10];
    for (i = 0; i < n; i++) 
        s[i] = 0;
    f=r=0;
    q[r] = source;
    s[source] = 1;
    while (f<=r) {
        u = q[f++];
        for(v=0; v<=n; v++){
            if (a[u][v] == 1 && s[v] == 0) {
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void bfs::write() {
    int  i;
    for (i=0; i<n; i++) {
        if (s[i] == 0)
            cout << " Vertex " << i << " is not reachable" << endl;
        else
            cout << " Vertex " << i << " is reachable" << endl;
    }
}

int main() {
    bfs B;
    B.read();
    B.BFS();
    B.write();
    return 0;
}