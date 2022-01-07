#include<bits/stdc++.h>
using namespace std;
// int m = pow(10,9)+7;
typedef unsigned long long int lli; //correction

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; //correction
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n, greater<int>());
        lli ans = 0;
        for(int i = 0; i < n; i++){
            lli temp = pow(2,i);
            ans = ans + (arr[i]*temp);
        }
        cout<<ans<<endl;
    }
    // write your code here
    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9)+7;
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
        sort(arr, arr+n, greater<int>());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long temp = pow(2,i);
            ans = (ans + (arr[i]*temp)%m)%m;
        }
        cout<<ans<<endl;
    }
    // write your code here
    return 0;
}
*/
