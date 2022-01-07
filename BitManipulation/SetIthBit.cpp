#include<bits/stdc++.h>
using namespace std;
int m = pow(10, 9) + 7;
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int i;
        cin>>n>>i;
        int z = (n|(1<<i))%m;//flip ith bit using xor and shift operator
        cout<<z<<endl;
    }
    return 0;
}
