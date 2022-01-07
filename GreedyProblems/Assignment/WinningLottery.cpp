/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int sum, d;
        cin>>sum>>d;
        int* arr = new int[d];
        if(d != 1){
            arr[0] = 1;
        }else{
            cout<<sum<<endl;
            break;
        }
        for(int i = 1; i < d; i++){
            arr[i] = 0;
        }
        sum = sum-1;
        for(int i = d-1; i >= 1; i--){
            if(sum >= 9){
                arr[i] = 9;
                sum = sum-9;
            }else{
                arr[i] = sum;
                sum = 0;
            }
        }
        if(sum != 0){
            arr[0] = arr[0] + sum;
        }
        int n = 0;
        for(int i = 0; i < d-1; i++){
            n = (n+arr[i])*10;
        }
        n += arr[d-1];
        cout<<n<<endl;
    }
    // write your code here
    return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int sum, d;
        cin>>sum>>d;
        int* arr = new int[d];
        if(d != 1){
            arr[0] = 1;
        }else{
            cout<<sum<<endl;
            continue;
        }
        for(int i = 1; i < d; i++){
            arr[i] = 0;
        }
        sum = sum-1;
        for(int i = d-1; i >= 1; i--){
            if(sum >= 9){
                arr[i] = 9;
                sum = sum-9;
            }else{
                arr[i] = sum;
                sum = 0;
            }
        }
        if(sum != 0){
            arr[0] = arr[0] + sum;
        }
        for(int i = 0; i < d; i++){
            cout << arr[i];
        }
        cout << endl;
        // int n = 0;
        // for(int i = 0; i < d-1; i++){
        //     n = (n+arr[i])*10;
        // }
        // n += arr[d-1];
        // cout<<n<<endl;
    }
    // write your code here
    return 0;
}
