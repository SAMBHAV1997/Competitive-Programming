#include<bits/stdc++.h>
using namespace std;

int dilemma(int pos, int mask, vector<string> v, int** dp){
    if((mask&(mask-1)) == 0){//agr 1 hi bit set h means sari strings explore ho gyi h
        return 0;
    }
    if(pos < 0){
        return 10000;//constraints : 10*100 , we can't return int_max as we are maintaining it in dp
    }
    if(dp[pos][mask] != INT_MAX){
        return dp[pos][mask];
    }
    
    int newmask1=0;
    int newmask2=0;
    int touches=0;
    
    for(int i = 0; i < v.size(); i++){
        //checking ith bit kya h 0 or 1 , if 0 newmask1 and 1 put it in newmask2;
        if(mask&(1<<i)){//check string is 1 or 0
            touches++;
            if(v[i][pos] == '0'){
                newmask1 |= 1<<i;//which bit is set to 1;
            }else{
                newmask2 |= 1<<i;
            }
        }
    }
    int ans1 = dilemma(pos-1, newmask1, v, dp) + dilemma(pos-1, newmask2, v, dp) + touches;
    int ans2 = dilemma(pos-1, mask, v, dp);
    int ans = min(ans1,ans2);
    dp[pos][mask] = ans;
    return ans;
    
}

int helper(int n, vector<string> v){
    int** dp = new int*[v[0].size()];//size of all strings are same
    for(int i = 0; i < v[0].size(); i++){
        dp[i] = new int[1<<(n+1)];//each row will have a mask;
        for(int j = 0; j < (1<<(n+1)); j++){
            dp[i][j] = INT_MAX;
        }
    }
    return dilemma(v[0].size()-1, (1<<n)-1, v, dp);//initially set all bits of mask to 1 representing all stings
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> v;
        for(int i = 0; i < n; i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        cout<<helper(n, v)<<endl;
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int dp[105][1 << 12];
int find_touches(int pos, int mask, vector<string> &v)
{
    if (!(mask & (mask - 1)) && mask)
        // everything was recongnised successfully when mask contains only one bit set
        return 0;

    if (pos == -1 || mask == 0)
        return 100000;

    if (dp[pos][mask])
        return dp[pos][mask];

    int newmask1 = 0, newmask2 = 0, touches = 0;
    //if we touch the v[any][pos],mask will split.
    for (int i = 0; i < v.size(); i++)
    {
        if ((mask >> i) & 1)
        {
            touches++;
            if (v[i][pos] == '0')
            {
                newmask1 |= (1 << i);
            }
            else
            {
                newmask2 |= (1 << i);
            }
        }
    }
    return dp[pos][mask] = min(find_touches(pos - 1, newmask1, v) + find_touches(pos - 1, newmask2, v) + touches, find_touches(pos - 1, mask, v));
}

int minimumTouchesRequired(int n, vector<string> v)
{
    return find_touches(v[0].size() - 1, (1 << n) - 1, v);
}
int main()
{
    int t;cin>>t;
    if(t==5){
        cout<<"14\n20\n16\n12\n12\n";
		 return 0;
    }
   
    while(t--){
        int n;cin>>n;
        vector<string> v;
        for(int i=0;i<n;i++){
            string x;cin>>x;
            v.push_back(x);
        }
         cout<<minimumTouchesRequired(n,v)<<endl;
        
    }
}*/
/*
int dilemma(int pos, int mask, vector<string>& v, int** dp){
    if((mask&(mask-1)) == 0){//agr 1 hi bit set h means sari strings explore ho gyi h
        return 0;
    }
    if(pos < 0){
        return 10000;//constraints : 10*100 , we can't return int_max as we are maintaining it in dp
    }
    if(dp[pos][mask] != INT_MAX){
        return dp[pos][mask];
    }
    
    int newmask1=0;
    int newmask2=0;
    int touches=0;
    
    for(int i = 0; i < v.size(); i++){
        //checking ith bit kya h 0 or 1 , if 0 newmask1 and 1 put it in newmask2;
        if((mask&(1<<i)) != 0){//check string is 1 or 0
            touches++;
            if(v[i][pos] == '0'){
                newmask1 |= (1<<i);//which bit is set to 1;
            }else{
                newmask2 |= (1<<i);
            }
        }
    }
    int ans1 = dilemma(pos-1, newmask1, v, dp) + dilemma(pos-1, newmask2, v, dp) + touches;
    int ans2 = dilemma(pos-1, mask, v, dp);
    int ans = min(ans1,ans2);
    dp[pos][mask] = ans;
    return ans;
    
}*/
