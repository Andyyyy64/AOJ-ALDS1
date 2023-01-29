#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int bubblesort(int A[MAX],int N) {
    int flg;
    int tmp;
    int cnt = 0;
    flg = true;
    while(flg){
        flg = false;
        for(int j = N-1; j > 0 ; --j){
            if(A[j] < A[j - 1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flg = true;
                cnt++;
            }
        }
    }
    for(int i = 0;i < N;++i){
        if( i != N - 1){
            cout << A[i];
            cout << " ";
        }else{
            cout << A[i];
        }
        }
        cout << endl;
    return cnt;
}

int main(){
    int A[MAX];
    int N,cnt;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    cnt = bubblesort(A,N);
    cout << cnt << endl;
    return 0;
}