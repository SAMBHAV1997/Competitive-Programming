#include<bits/stdc++.h>
using namespace std;

int makeSeive(int n){
    bool isPrime[n+1];
    memset(isPrime ,true, sizeof(isPrime));
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i] == true){
            for(int j = i*i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    int primeCount = 0;
    int nonPrimeCount = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            primeCount += 1;
        }else{
            nonPrimeCount += 1;
        }
    }
    if(primeCount > nonPrimeCount){
        cout<<2<<endl;
        cout<<nonPrimeCount<<" "<<primeCount;
    }else{
        cout<<2<<endl;
        cout<<primeCount<<" "<<nonPrimeCount;
    }
}

int main(){
  	int n;
    cin>>n;
    if(n == 0){
        cout<<1<<endl;
        cout<<0<<" "<<0;
    }else if(n == 1){
        cout<<1<<endl;
        cout<<0<<" "<<1;
    }else{
    	makeSeive(n+1);
    }
    // write your code here
    return 0;
}




















/*

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int n;
    cin >> n;
    bool isPrime[n + 2];
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2; i<=n+1; i++) {
        if(isPrime[i]) {
            for(int j=2; j*i<=n+1; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    int cnt1=0, cnt2=0;
    if(n <= 1) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    for(int i=2; i<=n+1; i++) {
        if(isPrime[i]) cnt1++;
        else cnt2++;
    }
    cout << min(cnt1, cnt2) << " " << max(cnt1, cnt2) << endl;
    return 0;
}
*/
