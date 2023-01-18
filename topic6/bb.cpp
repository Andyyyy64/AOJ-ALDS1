#include <iostream>
using namespace std;

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p-1;
    for (int j = p; j <= r-1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int q = partition(A, 0, n-1);

    for (int i = 0; i < q; i++) {
         cout << A[i] << " ";
    }
    cout << "[" << A[q] << "]";
    for (int i = q+1; i < n; i++) {
        if(i!=n - 1)
            cout << " " << A[i];
        else cout << " " << A[i] << endl;
    }
    return 0;
}