#include<bits/stdc++.h>
using namespace std;

int minDiff(int* arr, int n, int k){
    int dif = arr[n-1] - arr[0];
    int big = arr[n-1]-k;
    int small = arr[0]+k;
    if(small > big){
        int temp = small;
        small = big;
        big = temp;;
    }
    for(int i = 1; i < n-1; i++){
        int subtractValue = arr[i]-k;
        int addValue = arr[i]+k;
        if(subtractValue >= small || addValue <= big){
            continue;
        }else{
            if((big-subtractValue) <= (addValue-small)){
                small = subtractValue;
            }else{
                big = addValue;
            }
        }
    }
    return min(dif, (big-small));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        cout<<minDiff(arr, n, k)<<endl;
    }
    // write your code here
    return 0;
}
