
/*#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;
long long abc(int n, int bitCount, int first, long long*** dp, int i, int j){
    if(i == n){
        if(bitCount == j){
            return 1;
        }else{
            return 0;
        }
    }
    if(j > bitCount){
        return 0;
    }
    if(dp[i][j][first] > -1){
        return dp[i][j][first];
    }
    if(first == 0){
        long long option1 = ((abc(n, bitCount, 0, dp, i+1, j))%m + 
                            (abc(n, bitCount, 1, dp, i+1, j))%m)%m;
        dp[i][j][first] = option1;
        return option1;
    }else{
        long long option2 = ((abc(n, bitCount, 1, dp, i+1, j+1))%m + 
            				(abc(n, bitCount, 0, dp, i+1, j))%m)%m;
        dp[i][j][first] = option2;
        return option2;
    }
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int bitCount;
        cin>>n>>bitCount;
        long long*** dp = new long long**[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new long long*[bitCount+1];
            for(int j = 0; j <= bitCount; j++){
                dp[i][j] = new long long[2];
                for(int x = 0; x <= 1; x++){
                    dp[i][j][x] = -1;
                }
            }
        }
        cout<<abc(n, bitCount, 0, dp, 0, 0)<<endl;
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;

long long dp[101][101][2];
long long abc(int n, int k, int first){
    if(dp[n][k][first] != -1){
        return dp[n][k][first];
    }
    
    //base case
    if(n == 1){
        if(k == 0){
            dp[n][k][first] = 1;
            return 1;
        }else{
            dp[n][k][first] = 0;
            return 0;
        }
    }
    if(k < 0){
        dp[n][k][first] = 0;
            return 0;
    }
    
    if(first == 0){
        long long option1 = ((abc(n-1, k, 1))%m + 
                            (abc(n-1, k, 0))%m)%m;
        dp[n][k][first] = option1;
        return option1;
    }else{
        long long option2 = ((abc(n-1, k-1, 1))%m + 
            				(abc(n-1, k, 0))%m)%m;
        dp[n][k][first] = option2;
        return option2;
    }
    return dp[n][k][first];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    for(int i = 0; i <= 101; i++){
            // dp[i] = new long long*[101];
            for(int j = 0; j <= 101; j++){
                // dp[i][j] = new long long[2];
                for(int x = 0; x <= 1; x++){
                    dp[i][j][x] = -1;
                }
            }
        }
    
    while(t--){
        int n;
        int bitCount;
        cin>>n>>bitCount;
        // long long*** dp = new long long**[n+1];
        // for(int i = 0; i <= n; i++){
        //     dp[i] = new long long*[bitCount+1];
        //     for(int j = 0; j <= bitCount; j++){
        //         dp[i][j] = new long long[2];
        //         for(int x = 0; x <= 1; x++){
        //             dp[i][j][x] = -1;
        //         }
        //     }
        // }
        
        long long consider_first_bit_1 = abc(n, bitCount, 1) % m;
        long long consider_first_bit_0 = abc(n, bitCount, 0) % m;
    
        long long count = (consider_first_bit_1 + consider_first_bit_0) % m;
        
        cout<<count<<endl;
    }
    return 0;
}
