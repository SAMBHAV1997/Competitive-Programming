#include<bits/stdc++.h>
using namespace std;

int keypad(string arr[], int n, string output[]){
    if(n == 0 || n == 1){
        output[0] = "";
        return 1;
    }
    //int key = n%10;
    string smallString = arr[n%10];
    int smalloutputsize = keypad(arr, n/10, output);
    int k = 0;
    for(int i = 0; i < (smallString.size()-1)*smalloutputsize; i++){
        output[i+smalloutputsize] = output[i];
    }
    for(int i = 0; i < smallString.size(); i++){
        for(int j = 0; j < smalloutputsize; j++){
            output[k] = output[k] + smallString[i];
            k++;
        }
    }
   
    return smallString.size()*smalloutputsize;
}

int main(){
    // write your code here
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string* output = new string[100000];
        int count = keypad(arr,n,output);
        for(int i = 0; i < count; i++){
            cout<<output[i]<<'\n';
        }
    }
    return 0;
}
