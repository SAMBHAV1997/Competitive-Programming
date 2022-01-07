/*#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;
long long subsequences(string s, long long* dp, unordered_map<char, int> a){
    for(int i = 1; i <= s.size(); i++){
        dp[i] = (2*(dp[i-1]%m))%m;
        if(a.count(s[i-1])){
            int j = a[s[i-1]];
            dp[i] = (dp[i] - dp[j-1])%m;
        }
        a[s[i-1]] = i;
    }
    return dp[s.size()];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long* dp = new long long[s.size()+1];
        dp[0] = 1;
        unordered_map<char, int> a;
        cout<<subsequences(s, dp, a)<<endl;
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;
long long subsequences(string s, long long* dp, unordered_map<char, int> a){
    for(int i = 1; i <= s.size(); i++){
        dp[i] = (2*(dp[i-1]%m))%m;
        if(a.count(s[i-1])){
            int j = a[s[i-1]];
            if(dp[i]<dp[j-1]){
                dp[i] = (dp[i] - dp[j-1] + m)%m;
            }
            else
            	dp[i] = (dp[i] - dp[j-1])%m;
        }
        a[s[i-1]] = i;
    }
    return dp[s.size()];
}

int main(){
    // write your code here
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long* dp = new long long[s.size()+1];
        dp[0] = 1;
        unordered_map<char, int> a;
        cout<<subsequences(s, dp, a)<<endl;
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;
long long subsequences(string &s, long long* dp){
    
    int last[100];
    memset(last, -1, sizeof(last));
    for(int i = 1; i <= s.size(); i++){
        dp[i] = (2*(dp[i-1]%m))%m;
        if(last[(s[i-1])]!=-1){
            int j = last[s[i-1]];
            if(dp[i]<dp[j-1]){
                dp[i] = (dp[i] - dp[j-1] + m)%m;
            }
            else
            	dp[i] = (dp[i] - dp[j-1])%m;
        }
        last[s[i-1]] = i;
    }
    return dp[s.size()];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);//this line basically fastens the input output of the code
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long* dp = new long long[s.size()+1];
        dp[0] = 1;
        // unordered_map<char, int> a;
        cout<<subsequences(s, dp)<<endl;
    }
    return 0;
}*/
