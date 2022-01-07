/*#include<bits/stdc++.h>
using namespace std;

int makeSeive(int n){
    bool isPrime[n+1];
    for(int i = 0; i <= n; i++){
        isPrime[i] = true;
    }
    //isPrime[0] = false;
    //isPrime[1] = false;
    int primeCount[n+1];
    for(int i = 0; i <= n; i++){
        primeCount[i] = 0;
    }
    for(int i = 2; i <= n; i++){
        if(isPrime[i] == true){
            for(int j = 2; j*i <= n; j ++){
                isPrime[j*i] = false;
                primeCount[j*i] += 1; 
            }
        }
    }
    
    int ans = 0;
    for(int i = 4; i <= n; i++){
        int count = 0;
        if(isPrime[i] == false){
        	for(int j = 2; j <= (i/2); j++){
            	if(i%j == 0 && isPrime[j] == true){
                	count++;
            	}
        	}
        }
        if(count == 2){
            ans += 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<makeSeive(n);
    // write your code here
    return 0;
}
*/

/* Time complexity: O(N*(log(log(N))) 
Space complexity: O(N) where N is the input */
#include <bits/stdc++.h> 
using namespace std; 
int solve(int n) { 
    bool isPrime[n + 1]; 
    memset(isPrime, true, sizeof(isPrime));
    int primeCount[n + 1]; 
    memset(primeCount, 0, sizeof(primeCount));
    for (int i = 2; i <= n; i++) { 
        if (isPrime[i] == true) {
            for (int j = 2; j * i <= n; j++) {
                isPrime[i * j] = false; 
                primeCount[i * j]++; }
        }
    } 
    int ans = 0; 
    for (int i = 1; i <= n; i++) { 
        if (primeCount[i] == 2) { 
            ans++; } 
    } 
    return ans; 
} 

int main() { 
    int n; 
    cin >> n; 
    cout << solve(n) << endl; 
}

