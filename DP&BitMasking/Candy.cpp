#include<bits/stdc++.h>
using namespace std;

long candy(int** like, int n, int curStudent, int mask, long* dp){
    if(curStudent >= n){
        return 1; 
    }
    if(dp[mask] > -1){
        return dp[mask];
    }
    long ans = 0;
    //int k = 0;
    for(int j = 0; j < n; j++){
        if(!(mask & (1 << j))  && like[curStudent][j]){
            ans += candy(like, n, curStudent+1, mask|(1<<j) , dp);
        }
    }
    dp[mask] = ans;
    return ans;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int** like = new int*[n];
        for(int i = 0; i < n; i++){
            like[i] = new int[n];
            for(int j = 0; j < n; j++){
                cin>>like[i][j];
            }
        }
        long* dp = new long[1<<n];
        for(int i = 0; i < (1<<n); i++){
            dp[i] = -1;
        }
        cout<<candy(like, n, 0, 0, dp)<<endl;
    }
    return 0;
}
