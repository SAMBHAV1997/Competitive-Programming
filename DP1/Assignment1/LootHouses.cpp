#include<bits/stdc++.h>
using namespace std;

long long lootHouses(int* arr, int n){
    long long *dp = new long long[n];
    dp[0] = arr[0];
    dp[1] = max(arr[1],arr[0]);
    //long long max = 0;
    for(int i = 2; i < n; i++){
        long long temp = arr[i]+dp[i-2];
        dp[i] = max(temp, dp[i-1]);
    }
    //max = 0;
    // for(int i = 0; i < n; i++){
    //     if(dp[i] > max){
    //         max = dp[i];
    //     }
    // }
    return dp[n-1];
}

int main(){
    // write your code here
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<lootHouses(arr,n);
    return 0;
}
