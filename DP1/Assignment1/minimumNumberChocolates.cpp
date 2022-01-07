#include<bits/stdc++.h>
using namespace std;

int minimumChocolates(int* arr, int n){
    int i = 1;
    int *dp1 = new int[n];
    int *dp2 = new int[n];
    if(n == 1){
        return 1;
    }
    if(arr[0] > arr[1]){
        dp1[0] = 2;
        dp1[1] = 1;
    }else if(arr[0] < arr[1]){
        dp1[0] = 1;
        dp1[1] = 2;
    }else{
        dp1[0] = 1;
        dp1[1] = 1;
    }
    while(i < n-1){
        if(arr[i] < arr[i+1]){
            dp1[i+1] = dp1[i]+1;
        }else{
            dp1[i+1] = 1;
        }
        i++;
    }
    dp2[n-1] = dp1[n-1];
    i = n-1;
    while(i > 0){
        if(arr[i] < arr[i-1]){
            dp2[i-1] = dp2[i]+1;
        }else{
            dp2[i-1] = 1;
        }
        i--;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += max(dp1[i], dp2[i]);
    }
    return sum;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<minimumChocolates(arr,n)<<endl;
    }
    return 0;
}
