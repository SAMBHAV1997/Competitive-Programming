#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	//Write your code here
  	if(a < b){
      return gcd(b, a);
    }
    if(b == 0){
      return a;
    }
  	return gcd(b, a%b);
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        int b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    // write your code here
    return 0;
}

