#include<bits/stdc++.h>
using namespace std;

class quicksort {
    int  high, low, temp;
public:
    void sort(int *, int , int);
    int partition(int *, int , int);
};


int quicksort::partition(int *a, int low, int high) {
    int i, j ,key;
    i = low+1;
    j = high;
    key = a[low];
    while(1){
        while(i<high && a[i] <= key) 
            i++;
        while(j>=low && a[j] > key)
            j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quicksort::sort(int a[], int low, int high) {
    if(low < high) {
        int j = partition(a, low, high);
        sort(a, low, j-1);
        sort(a, j+1, high);
    }
}

int main(){
    int *a, n, i;
    quicksort q;
    cout << "Enter the number of elements: ";
    cin >> n;
    a = new int[n];
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    q.sort(a, 0, n-1);
    cout  << "The sorted elements are: " << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}