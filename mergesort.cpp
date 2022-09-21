#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

class mergesort
{
    int low, high;

public:
    void sort(int *, int, int);
    void merger(int *, int, int, int);
};

void mergesort::sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        sort(a, low, mid);
        sort(a, mid + 1, high);
        merger(a, low, mid, high);
    }
}

void mergesort::merger(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int c[MAX];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
        c[k++] = a[i++];
    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = c[i];
}

int main()
{
    int *a, n, i;
    clock_t start, stop;
    mergesort m;
    cout << "Enter the number of elements : ";
    cin >> n;
    a = new int[n];
    cout << "Enter the elements: " << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];
    start = clock();
    m.sort(a, 0, n - 1);
    stop = clock();
    cout << "Sorted elements anre : " << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}