#include<bits/stdc++.h>
using namespace std;
/*
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int ans = 0;
        int i = 1;
        while(i != n){
            ans = ans^i;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


1- Find the remainder of n by moduling it with 4. 
2- If rem = 0, then xor will be same as n. 
3- If rem = 1, then xor will be 1. 
4- If rem = 2, then xor will be n+1. 
5- If rem = 3 ,then xor will be 0.
*/
int xor_natural_num(int n){
    int val = n % 4;
    return (val == 0) ? n : ((val == 1) ? 1 : ((val ==2)?n+1:0));
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << xor_natural_num(n) << endl;
    }
    return 0;
}
