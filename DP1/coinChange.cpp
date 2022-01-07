#include<bits/stdc++.h>
using namespace std;

int coin_change(int* numD, int nd, int value, int** dp){
    if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }
    if(nd == 0){
        return 0;
    }
    if(dp[nd][value] != -1){
        return dp[nd][value];
    }
    int ans = coin_change(numD, nd, value-numD[0], dp) + coin_change(numD+1, nd-1, value, dp);
    dp[nd][value] = ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int nd;
        cin>>nd;
        int* numD = new int[nd];
        for(int i = 0; i < nd; i++){
            cin>>numD[i];
        }
        int value;
        cin>>value;
        int** dp = new int*[nd+1];
        for(int i = 0; i <= nd; i++){
            dp[i] = new int[value+1];
            for(int j = 0; j <= value; j++){
                dp[i][j] = -1;
            }
        }
        
        cout<<coin_change(numD, nd, value, dp)<<endl;
    }
    // write your code here
    return 0;
}






















/*
#include<bits/stdc++.h>
using namespace std;

long long coinChange(int* arr, int d, int v, long long** output){
    if(v == 0){
        return 1;
    }
    if(v < 0){
        return 0;
    }
    if(d == 0){
        return 0;
    }
    if(output[v][d] > -1){
        return output[v][d];
    }
    int m = pow(10,9)+7;
    long long a = coinChange(arr, d, v-arr[0], output);
    long long b = coinChange(arr+1, d-1, v, output);
    output[v][d] = (a+b)%m;
    return (a+b)%m;
    
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d;
        int *arr = new int[d+1];
        for(int i = 0; i < d; i++){
            cin>>arr[i];
        }
        int v;
        cin>>v;
        long long** output = new long long*[v+1];
        for(int i = 0; i <= v; i++){
            output[i] = new long long[d+1];
        }
        for (int i = 0; i <= v; i++) {
        	for (int j = 0; j <= d; j++) {
 
            // Assign values to the
            // memory blocks created
            	output[i][j] = -1;
        	}
    	}
        cout<<coinChange(arr, d, v, output)<<endl;
    }
    return 0;
}*/
