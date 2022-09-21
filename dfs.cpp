#include "bits/stdc++.h"
using namespace std;

class dfs {
    int n, a[10][10];
public:
    void read();
    void DFS(int u, int s[]);
    void reach();
    int connectivity();
};

void dfs::read() {
    int i,j;
    cout << "Enter number of nodes: " ;
    cin >> n;
    cout << "Enter adjacency matrix: " << endl;
    for (i=0; i<n; i++) 
        for(j=0; j<n; j++)  
        cin >> a[i][j];
}

void dfs::DFS(int u, int s[]) {
    int v;
    s[u] = 1;
    for(v=0; v<n; v++){
        if(a[u][v] == 1 && s[v] == 0)
            DFS(v,s);
    }
}

void dfs::reach() {
    int i, source, s[10];
    for(i=0; i< n; i++)
        s[i] = 0;
    cout << "Enter the source node: ";
    cin  >> source;
    DFS(source,s);
    for(i=0; i< n; i++){
        if(s[i] == 0)
            cout << "Vertex " << i << " is not reachable..!" << endl;
        else
            cout << "Vertex " << i << " is reachable..!" << endl;
    }
}

int dfs::connectivity() {
    int i,j,flag, s[10];
    for(j=0; j<n; j++){
        for(i=0; i<n; i++)
            s[i] = 0;
        DFS(j, s);
        flag = 1;
        for(i=0; i<n; i++){
            if(s[i] == 0)
                flag = 0;
        }
    }
    return flag;
}

int main() {
    dfs d;
    d.read();
    d.reach();
    int flag = d.connectivity();
    if(flag == 1)
        cout << "Graph is connected" << endl;
    else    
        cout << "Graph is not connected." << endl;
    
    return 0;
}