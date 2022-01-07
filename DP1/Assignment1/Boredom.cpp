#include<bits/stdc++.h>
using namespace std;

int boredom(int* arr, int* freq, int n){
    int *dp = new int[1001];
    dp[0] = 0;
    for(int i = 1; i < 1001; i++){
        dp[i] = max(dp[i-2]+(i*freq[i]), dp[i-1]);
    }
    return dp[1000];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int *freq = new int[1000];
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        cout<<boredom(arr, freq, n)<<endl;
    }
    return 0;
}
