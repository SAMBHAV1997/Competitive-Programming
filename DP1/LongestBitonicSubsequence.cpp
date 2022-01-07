#include<bits/stdc++.h>
using namespace std;

int bitonic(int* input, int n){
    int *lis = new int[n];
    //int index;
    //bool a = true;
    //output.push_back(1,0);
    int *lds = new int[n];
    lis[0] = 1;
    lds[0] = 1;
    for(int i = 1; i < n; i++){
        //output.push_back(1,0);
        lis[i] = 1;
        //lds[i] = 1;
        for(int j = i-1; j >= 0; j--){
            if(input[j] < input[i]){
                int posAns = lis[j] + 1;
                if(posAns > lis[i]){
                    lis[i] = posAns;
                }
            }
        }
        // for(int j = n-1; j >= i; j--){
        //     if(input[j] < input[i]){
        //         int posAns = lds[j] + 1;
        //         if(posAns > lis[i]){
        //             lds[i] = posAns;
        //         }
        //     }
        // }
    }
    for(int i = n-1; i >= 0; i--){
        lds[i] = 1;
        for(int j = i-1; j < n; j++){
            if(input[j] < input[i]){
                int posAns = lds[j] + 1;
                if(posAns > lds[i]){
                    lds[i] = posAns;
                }
            }
        }
    }
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    for(int i = 0; i < n; i++){
        int sum = lis[i] + lds[i];
        if(sum > max1){
            max1 = sum;
        }
    }
    max1 = max1-1;
    for(int i = 0; i < n; i++){
        int sum = lis[i];
        if(sum > max2){
            max2 = sum;
        }
    }
     for(int i = 0; i < n; i++){
        int sum = lds[i];
        if(sum > max3){
            max3 = sum;
        }
    }
    int x = max(max1, max2);
    return max(max3, x);
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *input = new int[n];
        for(int i = 0; i < n; i++){
            cin>>input[i];
        }
        cout<<bitonic(input, n)<<endl;
    }
    return 0;
}
