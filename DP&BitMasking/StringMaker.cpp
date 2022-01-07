/*#include<bits/stdc++.h>
using namespace std;

int findWays(string a, string b, string c, int x, int y, int z){
    if(z < 0){
        return 1;
    }
    if(x < 0 || y < 0){
        return 0;
    }
    int ways = 0;
    for(int i = 0; i < a.size()-1; i++){
        if(a[i] == c[z]){
            ways += findWays(a, b, c, i, y-1, z-1);
        }
    }
    for(int j = 0; j < b.size()-1; j++){
        if(b[j] == c[z]){
            ways += findWays(a, b, c, x-1, j, z-1);
        }
    }
    return ways;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string a;
        string b;
        string c;
        cin>>a>>b>>c;
        cout<<findWays(a, b, c, a.size()-1, b.size()-1, c.size()-1)<<endl;
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9)+7;
int findWays(string a, string b, string c, int*** dp){
    if(c.size() == 0){
        return 1;
    }
    if(a.size() == 0 && b.size() == 0){//correction1
        return 0;
    }
    if(dp[a.size()][b.size()][c.size()] != -1){
        return dp[a.size()][b.size()][c.size()];
    }
    int ways = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == c[0]){
            ways = (ways + findWays(a.substr(i+1), b, c.substr(1), dp))%m;
        }
    }
    for(int j = 0; j < b.size(); j++){
        if(b[j] == c[0]){
            ways = (ways + findWays(a, b.substr(j+1), c.substr(1), dp))%m;
        }
    }
    dp[a.size()][b.size()][c.size()] = (ways)%m;
    return ways;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string a;
        string b;
        string c;
        cin>>a>>b>>c;
        int*** dp = new int**[a.size()+1];
        for(int i = 0; i <= a.size(); i++){
            dp[i] = new int*[b.size()+1];
            for(int j = 0; j <= b.size(); j++){
                dp[i][j] = new int[c.size()+1];
                for(int k = 0; k <= c.size(); k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        cout<<findWays(a, b, c, dp)<<endl;
    }
    return 0;
}
