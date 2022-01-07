#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        unordered_map<int, int> a;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            a[arr[i]] += 1;
        }
        unordered_map<int, int> :: iterator it;
        for(it = a.begin(); it != a.end(); it++){
            if((it->second)&1 != 0){
                cout<<it->first<<endl;
                //return 0;
            }
        }
    }
    return 0;
}
