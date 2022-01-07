#include<bits/stdc++.h>
using namespace std;

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long n;
        long long k;
        cin>>n>>k;
        long long* arr = new long long[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long newCost = 0;
        long long oldCost = 0;
        long long s = arr[0];
        for(int i = 1; i < k; i++){
            newCost=oldCost+i*arr[i]-s;
            s+=arr[i];
            oldCost = newCost;
        }
        long long min = oldCost;
        for(int i = k; i < n; i++){
            s-=arr[i-k];
            newCost=oldCost-(2LL*s)+((k-1)*arr[i-k])+((k-1)*arr[i]);
            oldCost = newCost;

            s+=arr[i];

            if(newCost<min)
                min=newCost;
        }
        cout<<min<<endl;
    }
    return 0;
}
