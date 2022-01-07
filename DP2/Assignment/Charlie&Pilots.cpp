#include<bits/stdc++.h>
using namespace std;

long long charliePilots(int* ass, int* cap, int n, int diff, int i, long long** dp){
    if(i == n){
        return 0;
    }
    if(dp[i][diff] > -1){
        return dp[i][diff];
    }
    long long option1 = 0;
    long long option2 = 0;
    long long option3 = 0;
    if(diff == 0){
        option1 = ass[i] + charliePilots(ass, cap, n, diff+1, i+1, dp);
    }else if(diff == n-i){
        option2 = cap[i] + charliePilots(ass,cap, n, diff-1, i+1, dp);
    }else{
        option3 = min(ass[i]+charliePilots(ass, cap, n, diff+1, i+1, dp),
                      cap[i]+charliePilots(ass, cap, n, diff-1, i+1, dp));
    }
    long long ans = option1 + option2 + option3;
    dp[i][diff] = ans;
    return ans;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* ass = new int[n];
        int* cap = new int[n];
        for(int i = 0; i < n; i++){
            cin>>cap[i]>>ass[i];
        }
        long long** dp = new long long*[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new long long[(n/2)+1];
            for(int j = 0; j <= (n/2); j++){
                dp[i][j] = -1;
            }
        }
        cout<<charliePilots(ass, cap, n, 0, 0, dp)<<endl;
    }
    return 0;
}
