#include<bits/stdc++.h>
using namespace std;

int specialPrime(int n){
    bool isPrime[n+1];
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i] == true){
        	for(int j = i*i; j <= n; j +=i){
            	isPrime[j] = false;
        	}
        }
    }
    vector<int> primeNumber;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            primeNumber.push_back(i);
        }
    }
    int j = 0;
    int k = 1;
    int count = 0;
    for(int i = 2; i < primeNumber.size()-1; i++){
        // k=i+1;
        // while(k < primeNumber.size()){
        //     if(primeNumber[i]+primeNumber[i+1]+1 == primeNumber[k]){
        //         count += 1;
        //     }
        //     // else{
        //     //     j++;
        //     //     k++;
        //     // }
        //     k++;
        // }
        if(binary_search(primeNumber.begin(),primeNumber.end(),(primeNumber[i]+primeNumber[i+1] + 1))){
        	count++;
    	}
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<specialPrime(n);
    // write your code here
    return 0;
}
