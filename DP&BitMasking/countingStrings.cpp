
#include<bits/stdc++.h>
using namespace std;
const int m= 1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        long long ans=0;
        long long x=0;
        for(int i=0;i<n;i++){
            ans+=((x+1)%m)*('Z'-s[i]);
            x=((26*x)%m)+('Z'-s[i]);
        }
        cout<<ans%m<<endl;
    }
    return 0;
}
