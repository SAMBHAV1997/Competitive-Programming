#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int i;
        cin>>n>>i;
        int m = (1<<i)-1;
        int z = n&m;
        cout<<z<<endl;
    }
    return 0;
}
