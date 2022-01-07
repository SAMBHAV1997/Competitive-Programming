#include<bits/stdc++.h>
using namespace std;

int knapsackR(int* arrw, int* arrv, int** dp, int n, int wt){
	if(n == 0 || wt == 0){
        return 0;
    }
    if(dp[n][wt] > -1){
        return dp[n][wt];
    }
    int a=0;
    int ans;
    if(arrw[n-1] <= wt){
		a = arrv[n-1] + knapsackR(arrw, arrv, dp, n-1, wt-arrw[n-1]);
    }
    int b = knapsackR(arrw, arrv, dp, n-1, wt);
    ans = max(a,b);
    dp[n][wt] = ans;
    return ans;
		
}

int knapsackI(int* arrw, int* arrv, int** dp, int n, int wt){
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= wt; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= wt; j++){
            dp[i][j] = dp[i-1][j];
            if(arrw[i-1] <= j){
                dp[i][j] = max(dp[i][j], arrv[i-1]+dp[i-1][j-arrw[i-1]]);
            }
        }
    }
    return dp[n][wt];
}

int main(){
    // write your code here
    int n;
    cin>>n;
    int* arrw = new int[n];
    int* arrv = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arrw[i];
    }
    for(int i = 0; i < n; i++){
        cin>>arrv[i];
    }
    int wt;
    cin>>wt;
    int** dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[wt+1];
        for(int j = 0; j <= wt; j++){
            dp[i][j] = -1;
        }
    }
    //cout<<knapsackI(arrw, arrv, dp, n, wt);
    cout<<knapsackR(arrw, arrv, dp, n, wt);
    return 0;
}
/*
for (int i = 0; i < max_weight + 1; i++)
	{
		zero[i] = 0;
		one[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (j - w[i - 1] >= 0)
			{
				one[j] = max(zero[j], v[i - 1] + zero[j - w[i - 1]]);
			}
			else
			{
				one[j] = zero[j];
			}
		}

		for (int j = 0; j <= max_weight; j++)
		{
			zero[j] = one[j];
			one[j] = 0;
		}
	}
	return zero[max_weight];
    
*/    
