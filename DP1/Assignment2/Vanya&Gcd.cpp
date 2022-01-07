#include<bits/stdc++.h>
using namespace std;
/*
long long vanyaGCD(int* arr, int n){
    int** dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[100];
    }
    for(int i = 0; i < n; i++){
        for(int k = i-1; k >= 0; k--){
            if(arr[k] < arr[i]){
                for(int g = 1; g <= 100; g++){
                    int ng = __gcd(arr[i], g);
                	dp[i][g] += dp[k][g];     
                }
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i <= n; i++){
        sum += dp[i][1];
    }
    return sum;
}
*/

long long vanyaGCD(int* arr, int n){
    long long** dp = new long long*[n];
    for(int i = 0; i < n; i++){
        dp[i] = new long long[100];
    }
    int m = pow(10,9)+7;
    for(int i = 0; i < n; i++){
        dp[i][arr[i]]=1;
        for(int k = i-1; k >= 0; k--){
            if(arr[k] < arr[i]){
                for(int g = 1; g <= 100; g++){
                    int ng = __gcd(arr[i], g);
                	dp[i][ng] = (dp[i][ng] + dp[k][g])%m;     
                }
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum + dp[i][1]) % m;
    }
    return sum%m;
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
        cout<<vanyaGCD(arr, n)<<endl;
    }
    return 0;
}
