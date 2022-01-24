#include<bits/stdc++.h>
using namespace std;

int subsetSumK(int* arr, int n, int k, int si){
    if(n == si){
        if(k == 0){
        	return 1;
        }else{
            return 0;
        }
    }
    
    int a = subsetSumK(arr, n, k-arr[si], si+1);
    int b = subsetSumK(arr, n, k, si+1);
    return a+b;
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
        int *arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<subsetSumK(arr, n, k, 0)<<endl;
    }
    return 0;
}
