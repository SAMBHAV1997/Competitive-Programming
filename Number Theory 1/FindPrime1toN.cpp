#include<iostream>
#include<cmath>
using namespace std;

int main(){
	// Write your code here
/*    int n;
    cin>>n;
    int count = 0;
    int j;
	for(int i = 2; i <= n; i++){
      for(j = 2; j < i; j++){
        if(i%j == 0){
          break;
        }
      }
      if(i == j){
        count++;
      }
    }	
  cout<<count;*/
    int n,count = 0;
	cin>>n;
    bool arr[n];
    for(int i = 0; i <= n; i++){
      arr[i] = true; 
    }
  	arr[0] == arr[1] == false;
  	for(int i = 2; i <= sqrt(n); i++){
      if(arr[i] == true){
        for(int j = i*i; j <= n; j+=i){
          arr[j] = false;
        }
      }
    }
    for(int i = 2; i <= n; i++){
      if(arr[i] == true){
        count++;
      }
    }
    cout<<count;
	return 0;
}
