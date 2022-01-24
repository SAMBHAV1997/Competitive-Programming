#include<bits/stdc++.h>
using namespace std;

long long power(int x, int y){
    if(y == 0){
        return 1;
    }
    int m = pow(10,9) + 7;
    long long a = power(x, y-1);
    long long ans = (a*x)%m;
    return ans;
}

int main(){    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int y;
        cin>>y;
        cout<<power(x, y)<<endl;
    }
    return 0;
}
