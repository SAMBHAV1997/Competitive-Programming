/*
#include<bits/stdc++.h>
using namespace std;


long long intresting(int* arr, int n, long long k, long long l){
    long long range = arr[0];
    long  long min_cost = INT_MAX;
    while(range <= arr[n-1]){
        long long inc = 0;
        long long dec = 0;
        long long cost = INT_MAX;
        for(int i = 0; i < n; i++){
            if(arr[i] > range){
                dec += arr[i]-range;
            }else if(arr[i] < range){
                inc += range-arr[i];
            }
        }
        if(inc >= dec){
            cost = (dec*k) + (inc-dec)*l;
            if(cost < min_cost){
                min_cost = cost;
            }
        }
         // if(inc > 0 && dec == 0){
         //     cost = inc*l;
         //     if(cost < min_cost){
         //         min_cost = cost;
         //     }
         // }
        range++;
    }
    return min_cost;
}

int main(){
    // write your code here
    int n; 
    cin>>n;
    long long k;
    cin>>k;
    long long l;
    cin>>l;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    // cout<<k<<" "<<l<<endl;
    // for(int i = 0; i < n; i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<intresting(arr, n, k, l);
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
long long mval = pow(2,63);
long long intresting(long long* arr, long long n, long long k, long long l){
    long long range = arr[0];
    long long min_cost = mval;
    while(range <= arr[n-1]){
        long long inc = 0;
        long long dec = 0;
        long long cost = mval;
        for(int i = 0; i < n; i++){
            if(arr[i] >= range){
                dec += arr[i]-range;
            }else if(arr[i] < range){
                inc += range-arr[i];
            }
        }
        if(inc >= dec){
            cost = (dec*k) + (inc-dec)*l;
            if(cost < min_cost){
                min_cost = cost;
            }
        }
        
        range++;
    }
    return min_cost;
}

int main(){
    // write your code here
    long long n; 
    cin>>n;
    long long k;
    cin>>k;
    long long l;
    cin>>l;
    long long *arr = new long long[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    // cout<<k<<" "<<l<<endl;
    // for(int i = 0; i < n; i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<intresting(arr, n, k, l);
    return 0;
}
