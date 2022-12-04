#include <iostream>
using namespace std;

#define MAX 100


void insertionSort(int A[MAX], int N)
{
    for (int i = 0; i < N; ++i)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}

int main()
{
    int i, j, N;
    int A[MAX];
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for(j = 0; j < N; j++){
        if(j > 0){
            cout << "";
        }
        cout << A[j];
    }
    cout << endl;

    insertionSort(A, N);
    return 0;
}