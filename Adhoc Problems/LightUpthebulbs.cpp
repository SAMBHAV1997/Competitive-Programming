/*#include<bits/stdc++.h>
using namespace std;

long long lightUpBulb(int* arr, int n, long long k, long long l){
    int noz = 0;
    for(int i = 0; i < n-1; i++){
        if(arr[0] == 0){
            noz++;
        }else{
            if(arr[i] == 1 && arr[i+1] == 0){
                noz++;
                i++;
            }
        }
    }
    
    return ((noz-1)*(min(k,l)) + l);
}

int main(){
    // write your code here
    int n;
    long long k;
    long long l;
    cin>>n>>k>>l;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<lightUpBulb(arr, n, k, l);
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

long long lightUpBulb(string arr, int n, long long k, long long l){
    int noz = 0;
    if(arr[0]=='0'){ 
        noz++;
    }
    for(int i = 0; i < n-1; i++){
            if(arr[i] == '1' && arr[i+1] == '0'){
                noz++;
        }
    }
    if(noz==0) return 0;
    return (noz-1)*min(k,l) + l;
}

int main(){
    // write your code here
    int n;
    long long k;
    long long l;
    cin>>n>>k>>l;
	string arr;
    cin>>arr;
    cout<<lightUpBulb(arr, n, k, l);
    return 0;
}
