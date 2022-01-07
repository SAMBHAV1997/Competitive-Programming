#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* arr, int n, int sum){
    bool** dp = new bool*[2];
    for(int i = 0; i <= 1; i++){
        dp[i] = new bool[sum+1];
    }
    for(int i = 0; i <= sum; i++){
        dp[0][i] = false;
    }
    dp[0][0] = true;
    dp[1][0] = true;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[flag][j] = dp[flag^1][j];
            if(j >= arr[i-1]){
                dp[flag][j] = dp[flag][j] || dp[flag^1][j-arr[i-1]];
            }
        }
        flag = flag^1;
    }
    bool result = dp[n][sum]; 
    for (int i = 0; i <= n; i++){
    	delete[] dp[i]; 
    }
    delete[] dp; 
    return result; }
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int sum;
        cin>>sum;
        bool a = subsetSum(arr, n, sum);
        if(a){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;


  bool subsetSum(int *arr, int n, int sum) { 
      //dp[i][j] is true if we can create arr subset sum of j from first i elements
      bool **dp = new bool *[n + 1]; 
      //If sum is 0, then answer is true
      for (int i = 0; i <= n; i++) 
      { dp[i] = new bool[sum + 1]; 
       dp[i][0] = true; } 
      //If sum is not 0 and set is empty, then answer is false
      for (int i = 1; i <= sum; i++) 
      { dp[0][i] = false; } 
      //Fill the table in bottom up manner
      for (int i = 1; i <= n; i++)
      { for (int j = 1; j <= sum; j++)
      { if (j < arr[i - 1]) 
      { dp[i][j] = dp[i - 1][j]; } 
       else { dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } } } 
      bool result = dp[n][sum]; 
      for (int i = 0; i <= n; i++) 
      { delete[] dp[i]; }
      delete[] dp; 
      return result; }

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int sum;
        cin>>sum;
        bool a = subsetSum(arr, n, sum);
        if(a){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}*/
