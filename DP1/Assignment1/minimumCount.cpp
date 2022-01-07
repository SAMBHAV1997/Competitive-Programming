/*#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count = 0;
        while(n > 0){
            int a = sqrt(n);
            //cout<<a<<endl;
            n = n - (a*a);
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
*/
/*
int squares(vector<int> &val,int sum,vector<vector<int>>&dp,int n)
{
//    cout<<"hi"<<endl;
    if(sum==0)
        return 0;
    if(n==0&&sum!=0||sum<0)
        return INT_MAX-1;
     if(dp[n][sum]!=-1)
         return dp[n][sum];
    return dp[n][sum]=min(1+squares(val,sum-pow(val[n-1],2),dp,n),squares(val,sum,dp,n-1));
}
*/

#include <bits/stdc++.h>
using namespace std;
int minCount(int n)
{
int dp[n + 1];
dp[0] = 0;
dp[1] = 1;
for (int i = 2; i <= n; ++i)
{
dp[i] = INT_MAX;
for (int j = 1; i - (j * j) >= 0; j++)
{
dp[i] = min(dp[i], dp[i - (j * j)]);
}
dp[i] += 1;
}
return dp[n];
}
int main()
{
int t;
cin >> t;
while (t--)
{
int n;
cin >> n;
cout << minCount(n) << endl;
}
}
