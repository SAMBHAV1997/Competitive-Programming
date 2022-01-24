#include<bits/stdc++.h>
using namespace std;

int balancedTrees(int h){
    if(h == 1 || h == 0){
        return 1;
    }
    int m = pow(10,9)+7;
    int x = (balancedTrees(h-1));
    int y = (balancedTrees(h-2));
    long res1 = (long)x*x;
    long res2 = (long)2*x*y;
    
    int ans1 = (int)(res1%m);
    int ans2 = (int)(res2%m);
    
    return (ans1+ans2)%m;
    
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
    int h;
    cin>>h;
    cout<<balancedTrees(h)<<endl;
    }
    return 0;
}
