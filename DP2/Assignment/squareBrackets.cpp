/*
#include<bits/stdc++.h>
using namespace std;

long long squareBrackets(bool* arr, int n, int nob, int ncb){
    if(nob > n && ncb > n){
        return 0;
    }
    if(nob == n && ncb == n){
        return 1;
    }
    long long option1 = 0;
    long long option2 = 0;
    long long option3 = 0;
    int cI = nob+ncb;
    if(nob == ncb || arr[cI] == true){
        option1 = 1 + squareBrackets(arr, n, nob+1, ncb);
    }else if(nob == n){
        option2 = 1 + squareBrackets(arr, n, nob, ncb+1);
    }else{
        option3 = option1 + option2;
    }
    return option1+option2+option3;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int* s = new int[k];
        for(int i = 0; i < k; i++){
            cin>>s[i];
        }
        bool* arr = new bool[2*n];
        int j = 0;
        for(int i = 0; i < 2*n; i++){
            if(s[j]-1 == i && j < k){
                arr[i] = true;
                j++;
            }else{
                arr[i] = false;
            }
        }
        cout<<squareBrackets(arr, n, 0, 0)<<endl;
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
long long squareBrackets(bool* arr, int n, int nob, int ncb,int **dp){
    if(nob > n || ncb > n){
        return 0;
    }
    if(nob == n && ncb == n){
        return 1;
    }
    if(dp[nob][ncb]!=-1)
        return dp[nob][ncb];
    long long option1 = 0;
    long long option2 = 0;
    long long option3 = 0;
    int cI = nob+ncb;
    if(nob == ncb || arr[cI] == true){
        option1 = squareBrackets(arr, n, nob+1, ncb,dp);
    }else if(nob == n){
        option2 =  squareBrackets(arr, n, nob, ncb+1,dp);
    }else{
        option3 = squareBrackets(arr, n, nob+1, ncb,dp) + squareBrackets(arr, n, nob, ncb+1,dp);
    }
    return dp[nob][ncb] = (option1+option2+option3)%mod;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        // int* s = new int[k];
        bool* arr = new bool[2*n];
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        for(int i = 0; i < k; i++){
            int x;
            cin>>x;
            arr[x-1]=true;
        }
        
        // int j = 0;
        // for(int i = 0; i < 2*n; i++){
        //     if(s[j]-1 == i && j < k){
        //         arr[i] = true;
        //         j++;
        //     }else{
        //         arr[i] = false;
        //     }
        // }
        cout<<squareBrackets(arr, n, 0, 0,dp)<<endl;
    }
    return 0;
}
