#include<bits/stdc++.h>
using namespace std;

class topo {
    int n, a[10][10], in[10];
public:
    void read();
    void find();
    void sort();
};

void topo::read() {
    int i, j;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the asjacency matrix: " << endl;
    for(i = 0; i < n; i++) 
        for(j = 0; j < n; j++)
            cin >> a[i][j];
}

void topo::find() {
    int i, j;
    for(i=0; i < n; i++){
        int sum = 0;
        for(j=0; j < n; j++) {
            sum += a[j][i];
        }
        in[i] = sum;
    }
}

void topo::sort() {
    int i, t[10], s[10], u, v;     // t=result array  s=visited stack
    find();
    int top = -1, k=0;
    // for(i = 0; i < 10; i++) {
    //     t[i] = 0;
    //     s[i] = 0;
    // }
    for (int i=0; i<n; i++) {
        if (in[i] == 0) 
            s[++top] = i;
    }
    while(top != -1) {
        u = s[top];
        // cout << u ;  - Debugging code
        top--;
        t[k++] = u;
        for(v=0; v<n; v++) {
            if(a[u][v] == 1){
                in[v]--; 
                if(in[v] == 0)
                    s[++top] = v;
            }
        }
    }

    cout << "Topological order sequence: " << endl;
    for(i=0; i<n; i++) 
        cout << t[i] << " ";
}

int main() {
    topo t;
    t.read();
    t.sort();
    return 0;
}