#include<bits/stdc++.h>
using namespace std;

long long natural(int n){
    if(n == 1){
        return 1;
    }
    int m = pow(10,9) + 7;
    long long a = natural(n-1);
    long long ans = a*n;
    long long a1 = ans%m;
    return a1;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
        cout<<natural(n)<<endl;
    }
    return 0;
}
