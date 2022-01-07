#include<bits/stdc++.h>
using namespace std;

int kAlgo(int* arrSum, int row){
    int max = INT_MIN;
    int curr = 0;
    for(int i = 0; i < row; i++){
        curr += arrSum[i];
        if(curr > max){
            max = curr;
        }
        if(curr < 0){
            curr = 0;
        }
    }
    return max;
}

int maxRectangle(int** arr, int row, int col){
    int* arrSum = new int[row];
    int max = INT_MIN;
    for(int left = 0; left < col; left++){
        for(int i = 0; i < row; i++){
            arrSum[i] = arr[i][left];
        }
        for(int right = left; right < col; right++){
            if(left != right){
                for(int i = 0; i < row; i++){
                    arrSum[i] += arr[i][right];
                }
            }
            int sum = kAlgo(arrSum, row);
            if(sum > max){
                max = sum;
            }
        }
    }
    return max;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        int** arr = new int*[n];
        for(int i = 0; i < n; i++){
            arr[i] = new int[m];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }
       cout<<maxRectangle(arr, n, m)<<endl; 
    }
    return 0;
}
