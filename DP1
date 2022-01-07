/*#include<bits/stdc++.h>
using namespace std;

int num_codes(string code, int* dp, int n){
    if(code.length() == 1 || code.length() == 0){
        return 1;
    }
    int a = num_codes(code.substr(0,code.length()-2), dp, n);
    int b = 0;
    int temp = stoi(code.substr(code.length()-2, code.length()-1));
    if(temp <= 26){
    	if(code.length() == 2){
        	b = num_codes(code.substr(0,code.length()-2) , dp, n);
    	}else{
        	b = num_codes(code.substr(0,code.length()-3) , dp, n);   
    	}
    }
    return a+b;
}

int main(){
	int t;
    cin>>t;
    while(t--){
        string code;
        cin>>code;
        int n = code.length();
        int* dp = new int[n];
        for(int i = 0; i < n; i++){
            dp[0] = -1;
        }
        cout<<(num_codes(code, dp, n))<<endl;
    }
    // write your code here
    return 0;
}




*/





















/*
#include<bits/stdc++.h>
using namespace std;

void alphaCode(string s){
    int *arr = new int[s.size()];
    for(int i = 0; i < s.size(); i++){
        arr[i] = s[i] - '0';
        //cout<<arr[i]<<" ";
    }
    int m = pow(10,9) +7;
    int *output = new int[s.size()+1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= s.size(); i++){
        if(arr[i-1] != 0){
        	output[i] = output[i-1];
        }else{
            output[i] = 0;
        }
        //output[i] = output[i-1];
        if(arr[i-2]*10 + arr[i-1] <= 26  && arr[i-2] != 0){
            long s =output[i] + output[i-2];
            output[i] = (int)(s%m);
        }
    }
    int ans = (output[s.size()])%(m);
    cout<<ans<<endl;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        alphaCode(s);
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

void alphaCode(string s){
    int m = pow(10,9) +7;
    int *arr = new int[s.size()];
    for(int i = 0; i < s.size(); i++){
        arr[i] = s[i] - '0';
        //cout<<arr[i]<<" ";
    }
    int *output = new int[s.size()+1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= s.size(); i++){
        if(arr[i-1] != 0){
        	output[i] = output[i-1];
        }else{
            output[i] = 0;
        }
        if(arr[i-2]*10 + arr[i-1] <= 26  && arr[i-2]*10 + arr[i-1] >= 10){
            long s = output[i]+output[i-2];
            output[i] = (int)(s%m);
        }
    }
    
    int ans = (output[s.size()])%(m);
    cout<<ans<<endl;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        alphaCode(s);
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int num_codes(string code){
    if(code.length() == 1 || code.length() == 0){
        return 1;
    }
    int a = num_codes(code.substr(0,code.length()-2));
    int b = 0;
    if(code.length() > 2){
    	int temp = stoi(code.substr(code.length()-2, code.length()-1));
        if(temp <= 26){
        	b = num_codes(code.substr(0,code.length()-3));   
        }
    }
    return a+b;
}

int main(){
	int t;
    cin>>t;
    while(t--){
        string code;
        cin>>code;
        cout<<num_codes(code)<<endl;
    }
    // write your code here
    return 0;
}


*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = pow(10,9) + 7;

ll num_codes(ll *arr, ll* dp, ll n){
    if(n == 1 || n == 0){
        return 1;
    }
    
    if(dp[n] > 0){ //added this check. If ans already exists, we don't call recursion. Simple return it.
    	return dp[n];
    } 
    
    ll a = 0;
    ll b = 0;
    
    if(arr[n-1] > 0){
        a = num_codes(arr, dp, n-1)%mod; // int a = num_codes(code.substr(0,code.length()-2), dp, n);
    }
    
    // int temp = stoi(code.substr(code.length()-2, code.length()-1));
    ll temp = arr[n-2]*10 + arr[n-1];
    if(temp <= 26 && arr[n-2] != 0){
    	// if(code.length() == 2){
        b = num_codes(arr, dp, n-2)%mod; // b = num_codes(code.substr(0,code.length()-2) , dp, n);
    	// }else{
        	// b = num_codes(code.substr(0,code.length()-3) , dp, n);   
    	// }
    }
    dp[n] = (a + b)%mod;
    return dp[n];
}

int main(){
	int t;
    cin>>t;
    while(t--){
        string code;
        cin>>code;
        ll n = code.length();
        ll *dp = new ll[n+1];
        ll *arr = new ll[n]; //made this arr for coneverting the string to int arr
        for(ll i = 0; i < n; i++){
            dp[i] = -1;
            arr[i] = code[i] - '0';
        }
        dp[n] = -1;
        cout<<(num_codes(arr, dp, n))<<endl;
    }
    // write your code here
    return 0;
}
