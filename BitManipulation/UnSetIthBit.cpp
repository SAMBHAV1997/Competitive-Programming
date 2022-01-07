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
        int z = n&~(1<<i);
        cout<<z<<endl;
    }
    return 0;
}
