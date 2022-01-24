#include<bits/stdc++.h>
using namespace std;
int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[100000];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        bool flag = 1;
        for(int i=0;i<n-2;i++){
            if(abs(arr[i]-i-1)<=2)
                continue;
            cout<<"NO\n";
            flag = 0;
            break;
        }
        
        if(!flag)
            continue;

        int swaps = 0;
        for(int i=n;i>0;i--){

            if(arr[i-1]==i)
                continue;
            if(i-2>=0&&arr[i-2]==i){
                arr[i-2] = arr[i-1];
                arr[i-1] = i;
                swaps+=1;
                continue;
            }
            if(i-3>=0&&arr[i-3]==i){
                arr[i-3] = arr[i-2];
                arr[i-2] = arr[i-1];
                arr[i-1] = i;
                swaps+=2;
                continue;
            }
            cout<<"NO\n";
            flag = 0;
            break;

        }
		if(flag)
            cout<<"YES"<<endl<<swaps<<"\n";
    }

    return 0;
}
