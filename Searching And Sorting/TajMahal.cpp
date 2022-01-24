#include<bits/stdc++.h>
using namespace std;

int main(){
    // write your code here
    int n;
    cin>>n;
    long long* arr = new long long[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int i = 0;
    int j = 0;
    while(i < n){
        if(arr[i]-j <= 0){
            cout<<i+1;
            break;
        }else{
            j++;
            i++;
        }
        if(i == n){
            i = 0;
        }
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int n;
    cin>>n;
    int* arr = new int[n];
    int mn=1e9+10;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        mn=min(mn,arr[i]);
    }
    mn=mn-(mn%n);
    
    for(int i = 0; i < n; i++)
        arr[i]=arr[i]-mn;
    
    int i = 0;
    int j = 0;
    while(1){
        if(arr[i]-j <= 0){
            cout<<i+1;
            return 0;
        }else{
            j++;
            //arr[i] = arr[i]-j;
            i++;
        }
        if(i == n){
            i = 0;
            
        }
    }
    return 0;
}
*/

/* Time complexity : O(N) Space complexity : O(1) wherer N is the size of input array You can also use the binary search solution for this approach */ 
/*
#include <iostream>
#include <climits>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int * arr = new long long int[n + 1];
    
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] -= i - 1;
    if (arr[i] < 0) arr[i] = 0;
    long long int temp = arr[i] / n;
    if (arr[i] % n != 0) temp += 1;
    arr[i] = (n * temp) + i;
  }
    
  long long int finalAnswer = INT_MAX, rv = -1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] < finalAnswer) {
      finalAnswer = arr[i];
      rv = i;
    }
  }
    
  cout << rv << endl;
}

*/



/*
#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
	int n;
	cin>>n;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int*t=new int [n];
	for(int i=0; i<n; i++)
	{
		if((arr[i]-i)%n==0)
		{
			t[i]=(arr[i]-i)/n;
		}
        else if(arr[i]-i<0)
        {
            t[i]=0;
        }
		else
		{
			t[i]=((arr[i]-i)/n)+1;
		}
	}
	int *ans=new int [n];
	int minimum=9999999999;
	int minimum_index=-1;
	for(int i=0; i<n; i++)
	{
		ans[i]=i+t[i]*n;
		if(ans[i]<minimum)
		{
			minimum=ans[i];
			minimum_index=i;
		}
	}
	cout<<minimum_index+1;
	
}*/
