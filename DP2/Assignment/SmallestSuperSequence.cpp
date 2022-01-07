#include<bits/stdc++.h>
using namespace std;

int shortSeq(string s, string t, int i, int j, int** dp){
    if(i == s.size() && j == t.size()){
        return 0;
    }
    if(dp[i][j] > -1){
        return dp[i][j];
    }
    if(i == s.size()){
        return t.size()-j;
    }
    if(j == t.size()){
        return s.size()-i;
    }
    int x = 0;
    int y = 0;
    if(s[i] == t[j]){
        x = 1 + shortSeq(s, t, i+1, j+1, dp);
        dp[i][j] = x;
        return x;
    }else{
        y = 1 + min(shortSeq(s,t,i+1,j, dp), shortSeq(s,t,i,j+1, dp));
        dp[i][j] = y;
        return y;
    }
}

int main(){
    // write your code here
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
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
        cout<<shortSeq(s,t, 0, 0, dp)<<endl;
    }
    return 0;
}
