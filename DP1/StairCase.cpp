#include<bits/stdc++.h>
using namespace std;
typedef long long int
int staircase(int n, int* dp){
    if(n == 0 || n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int a = staircase(n-1, dp) + staircase(n-2, dp) + staircase(n-3, dp);
    dp[n] = a;
    return a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* dp = new int[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        cout<<staircase(n, dp)<<endl;
    }
    // write your code here
    return 0;
}





















/*

#include<bits/stdc++.h>
using namespace std;

long long staircaseI(long long n){
    long long *arr = new long long[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    int m = pow(10,9)+7;
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3])%m;
    }
    return arr[n]%m;
}

long long staircaseR(long long n){
    if(n == 0 || n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    long long *arr = new long long[n+1];
    int m = pow(10,9)+7;
    if(arr[n] > 1){
        return arr[n];
    }
    //for(int i = 0; i <= n; i++){}
    long long a = staircaseR(n-1) + staircaseR(n-2) + staircaseR(n-3);
    arr[n] = a;
    return a%m;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        //cout<<staircaseR(n)<<endl;
        cout<<staircaseI(n)<<endl;
    }
    return 0;
}*/
