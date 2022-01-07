#include<bits/stdc++.h>
using namespace std;

long long traderProfit(int* arr, int n, int trans, bool ongoing, long long*** dp, int i, int j){
    if(i == n || j == 0){
        return 0;
    }
    if(dp[i][j][ongoing] > -1){
        return dp[i][j][ongoing];
    }
    long long option1 = traderProfit(arr, n, trans, ongoing, dp, i+1, j);
    long long option2 = 0;
    long long option3 = 0;
    if(ongoing){
        option2 = traderProfit(arr, n, trans, 0, dp, i+1, j-1) + arr[i];
    }else{
        if(trans > 0){
            option3 = traderProfit(arr, n, trans, 1, dp, i+1, j) - arr[i];
        }else{
            return 0;
        }
    }
    long long ans = max(option1, max(option2, option3));
    dp[i][j][ongoing] = ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int trans;
        cin>>trans;
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
    	
        long long*** dp = new long long**[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new long long*[trans+1];
            for(int j = 0; j <= trans; j++){
                dp[i][j] = new long long[2];
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        
        cout<<traderProfit(arr, n, trans, 0, dp, 0, trans)<<endl;
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= trans; j++)
                delete [] dp[i][j];
            delete [] dp[i];
        }
        delete [] dp;
    }
    // write your code here
    return 0;
}
