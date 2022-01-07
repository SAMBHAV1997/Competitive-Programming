#include<bits/stdc++.h>
using namespace std;
int returnFirstSetBit(int n)
{
    if(n==0)
    {
        return 0;
    }
    int i=0;
    while((n&(1<<i))==0)
    {
        i++;
    }
    return n^(1<<i);
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
    }

    // write your code here
    return 0;
}
