#include<bits/stdc++.h>
using namespace std;

int lcsR(string s1, string s2, int i, int j){
    
}

int lcs(string s1, string s2, int** dp){
    for(int i = 0; i <= s1.length(); i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= s2.length(); j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[s1.length()-i] == s2[s2.length()-j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s1;
    	cin>>s1;
        string s2;
        cin>>s2;
        int** dp = new int*[s1.length()+1];
        for(int i = 0; i <= s1.length(); i++){
            dp[i] = new int[s2.length()+1];
        }
        cout<<lcsR(s1,s2,0,0);
        //cout<<lcs(s1, s2, dp)<<endl;
    }
    return 0;
}

