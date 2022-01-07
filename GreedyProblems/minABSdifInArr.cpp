#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int dif = INT_MAX;
        for(int i = 0; i < n-1; i++){
            if(arr[i+1]-arr[i] < dif){
                dif = arr[i+1]-arr[i];
            }
        }
        cout<<dif<<endl;
    }
    // write your code here
    return 0;
}
