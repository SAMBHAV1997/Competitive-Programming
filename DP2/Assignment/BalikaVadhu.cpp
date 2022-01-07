#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;
long long balikaVadhu(string s1, string s2, int i, int j, int k, long long*** dp){
    if(k == 0){
        return 0;
    }
    if(i >= s1.size() || j >= s2.size()){
        return 0;
    }
    if(dp[i][j][k] > -1){
        return dp[i][j][k];
    }
    long long ans=0;
    if(s1[i]==s2[j])
    {
        long long temp=s1[i];
        long long op1=temp+balikaVadhu(s1,s2,i+1,j+1,k-1,dp);
        if(op1-temp==0 && k>1)
        {
            op1=0;
        }
        long long op2=balikaVadhu(s1,s2,i+1,j,k,dp);
        long long op3=balikaVadhu(s1,s2,i,j+1,k,dp);
        ans=max(op1,max(op2,op3));
    }
    else
    {
       long long op1=balikaVadhu(s1,s2,i+1,j,k,dp);
        long long op2=balikaVadhu(s1,s2,i,j+1,k,dp);
        ans=max(op1,op2);
    }
    /*if(s1[i] != s2[j]){
        long long option1 = (max(balikaVadhu(s1,s2,i+1,j,k,dp), balikaVadhu(s1,s2,i,j+1,k,dp)));
        ans = option1;
    }else{
        if(k != 0){
        	long long option2 = (int(s1[i]) + balikaVadhu(s1, s2, i+1, j+1, k-1,dp));
        	long long option3 = (max(balikaVadhu(s1,s2,i+1,j,k,dp), 
                                    balikaVadhu(s1,s2,i,j+1,k,dp)));
        	ans = (max(option2, option3));
        }else{
            return 0;
        }
    }*/
    dp[i][j][k] = ans;
    return ans;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s1;
        string s2;
        cin>>s1>>s2;
        int k;
        cin>>k;
        long long*** dp = new long long**[s1.size()+1];
        for(int i = 0; i <= s1.size(); i++){
            dp[i] = new long long*[s2.size()+1];
            for(int j = 0; j <= s2.size(); j++){
                dp[i][j] = new long long[k+1];
                for(int x = 0; x <= k; x++){
                    dp[i][j][x] = -1;
                }
            }
        }
        
        int ans = balikaVadhu(s1, s2, 0, 0, k, dp);
       /* if(ans < 0){
            cout << "0";
        }else{
            cout << ans;
        }*/
        cout <<ans<< endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int helper(string s1, string s2, int m, int n, int k, int***dp){
    if(m < k || n < k){
        return INT_MIN;
    }
    if(k <= 0){
        return 0;
    }
    if(dp[m][n][k] != -1){
        return dp[m][n][k];
    }
    int out1=0, out2=0, out3=0, ans=0;
    if(s1[m-1] == s2[n-1]){
        out1 = helper(s1, s2, m-1, n-1, k-1, dp) + s1[m-1];
        out2 = helper(s1, s2, m-1, n, k, dp);
        out3 = helper(s1, s2, m, n-1, k, dp);
        ans = max(out3, max(out1, out2));
    }else{
        out2 = helper(s1, s2, m-1, n, k, dp);
        out3 = helper(s1, s2, m, n-1, k, dp);
        ans =  max(out3, out2);
    }
    dp[m][n][k] = ans;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        int k;
        cin >> s1 >> s2 >> k;

        int n = s1.length();
        int m = s2.length();
		int*** dp = new int**[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = new int*[m+1];
            for(int j=0; j<=m; j++){
                dp[i][j] = new int[k+1];
                for(int a=0; a<=k; a++){
                    dp[i][j][a] = -1;
                }
            }
        }
        int ans = helper(s1, s2, n, m, k, dp);
        if(ans < 0){
            cout << "0";
        }else{
            cout << ans;
        }
        cout << endl;
    }
}*/
