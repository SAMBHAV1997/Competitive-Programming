#include<bits/stdc++.h>
using namespace std;

bool sort_the_skill(int* arr, int n){
    int i = 0;
    int j = 1;
    while(j < n){
        if(arr[i] > arr[j] && arr[i]-arr[j] == 1){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }else if(arr[i] > arr[j]){
            return false;
        }
        i++;j++;
    }
    return true;
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
        bool a = sort_the_skill(arr, n);
        if(a == true){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
        delete[] arr;
    }
    return 0;
}
