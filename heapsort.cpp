#include "bits/stdc++.h"
using namespace std;

class heapsort {
public:
    void sort(int *, int);
    void heapify(int *, int);
    void adjust(int *, int, int);
};

void heapsort::sort(int a[], int n){
    int i, temp;
    heapify(a, n);
    for(i = n-1; i > 0; i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjust(a, i, 0);
    }
}

void heapsort::heapify(int a[], int n){
    int i,j,k,p;
    for(i=1; i<n; i++){
        k = a[i];
        j=i;
        p = (j-1) / 2;
        while(j >0 && k > a[p]){
            a[i] = a[p];
            j = p;
            p = (j-1) / 2;
        }
        a[j] = k;
    }
}

void heapsort::adjust(int a[], int n, int p) {
    int i, item;
    item = a[p];
    i = 2*p+1;
    while(i < n) {
        if(i+1 < n) 
            if(a[i] < a[i+1])
                i++;
        if(item < a[i]){
            a[p] = a[i];
            p = i;
            i = 2 * p+1;
        }
        else break;
    }
    a[p] = item;
}

int main() {
    int *a, n, i;
    heapsort h;
    cout << "Enter number of elements: ";
    cin >> n;
    a = new int[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) 
        a[i] = rand();
    
    h.sort(a, n);
    cout << "Sorted elements are: " << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}