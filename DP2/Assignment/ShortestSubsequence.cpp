#include<bits/stdc++.h>
using namespace std;

int shortestSub(string s, string t, int i, int j, int** dp){
    if(j == t.size()){
        return 1;
    }
    if(i == s.size()){
        return INT_MAX-1;//because it can cross integer value that's why -1
    }
    if(dp[i][j] > -1){
        return dp[i][j];
    }
    int k;
    int option1 = shortestSub(s, t, i+1, j, dp);
    int option2 = INT_MAX;
    for(k = j; k < t.size(); k++){
        if(s[i] == t[k]){
            option2 = 1 + shortestSub(s, t, i+1, k+1, dp);
            break;
        }
    }
    if(k == t.size()){
    	return 1;
    }else{
    	int ans = min(option1, option2);
        dp[i][j] = ans;
        return ans;
    }
}

int main(){
    // write your code here
	string s;
    string t;
    cin>>s>>t;
    int** dp = new int*[s.size()+1];
    for(int i = 0; i <= s.size(); i++){
        dp[i] = new int[t.size()+1];
        for(int j = 0; j <= t.size(); j++){
            dp[i][j] = -1;
        }
    }
    cout<<shortestSub(s,t,0,0,dp);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

int shortestSub(string s, string t){
    if(s.size() == 0){
        return 100000;
    }
    if(t.size() == 0){
        return 1;
    }
    
    int option1 = shortestSub(s.substr(1), t);
    int k=0;
    for(k = 0; k < t.size(); k++){
        if(s[0] == t[k]){
            break;
        }
    }
    if(k == t.size())
        return 1;
    
    int option2 = 1 + shortestSub(s.substr(1), t.substr(k+1));
    return min(option1, option2);
}*/
/*
int helper(string s, string t, int m, int n, int** dp) {
    if(n==0)
        return 1;
    if(m==0)
        return 1001;
    if(dp[m][n] != -1)
        return dp[m][n];
    
	int a = helper(s.substr(1), t, m-1, n, dp);
    int b=INT_MAX;
    for(int i=0; i<n; i++) {
        if(t[i]==s[0]) {
            b = 1+helper(s.substr(1), t.substr(i+1), m-1, n-i-1, dp);
        	break;
    	}
        if(i==n-1)
            return 1;
    }
    dp[m][n] = min(a, b);
    return dp[m][n]
    }
    */
