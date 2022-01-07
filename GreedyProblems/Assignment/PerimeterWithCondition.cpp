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
        int i;
        sort(arr, arr+n, greater<int>());
        for(i = 0; i < n-2; i++){
            if(arr[i] < (arr[i+1]+arr[i+2])){
                cout<<arr[i+2]<<" "<<arr[i+1]<<" "<<arr[i]<<endl;
                break;
            }
        }
        if(i == n-2){
            cout<<-1<<endl;
        }
    }
    // write your code here
    return 0;
}
