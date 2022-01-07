#include<bits/stdc++.h>
using namespace std;

long long mehtaSab(pair<long long, long long>* arr, int n, int W){
    long long*** dp = new long long**[2];
    for(int i = 0; i < 2; i++){
        dp[i] = new long long*[n+1];
        for(int j = 0; j <= n; j++){
            dp[i][j] = new long long[W+1];
            for(int k = 0; k <= W; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    int primes[11] = {1,2,3,5,7,11,13,17,19,23,29};
    //base case
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            dp[0][i][j] = dp[0][i-1][j];
            if(j >= arr[i-1].second){
                dp[0][i][j] = max(dp[0][i][j], arr[i-1].first + dp[0][i-1][j-arr[i-1].second]);
            }
        }
    }
    
    //main sln
    for(int prime = 1; prime <= 10; prime++){
        int p = prime%2;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
                dp[p][i][j] = dp[p][i-1][j];
                if(j >= arr[i-1].second){
                    dp[p][i][j] = max(dp[p][i][j], max(dp[p][i-1][j-arr[i-1].second] + arr[i-1].first, 
                                      dp[p^1][i-1][j-arr[i-1].second] + arr[i-1].first * primes[prime]));
                }
            }
        }
    }
    return dp[0][n][W];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int W;
        cin>>n>>W;
        pair<long long, long long>* arr = new pair<long long, long long>[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr, arr+n);
        //int primes[11] = {1,2,3,5,7,11,13,17,19,23,29};
        cout<<mehtaSab(arr, n, W)<<endl;;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int primes[]={1,2,3,5,7,11,13,17,19,23,29};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,tw;
        cin>>n>>tw;
        
        long long p[n+1];
        long long w[n+1];
        
        for(int i=1;i<=n;i++)
            cin>>p[i]>>w[i];
        
                

        long long dp[n+1][tw+1]={0};
        vector <long long> v;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=tw;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(j<w[i])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],(p[i]+dp[i-1][j-w[i]]));
            }
        }

        int x=n,y=tw;
        while(x>0 && y>0){
            if(dp[x][y]!=dp[x-1][y]){
                v.push_back(p[x]);
                y=y-w[x];
                x=x-1;
            }
            else{
                x=x-1;
            }
        }

        int j=10;
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=v.size()-1;i>=0;i--){
            ans+=(v[i]*primes[j--]);
            if(j<0) j=0;
        }
        cout<<ans<<endl;
   	
   	
    }
    return 0;
}*/
