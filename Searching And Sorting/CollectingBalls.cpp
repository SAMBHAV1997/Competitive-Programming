#include<bits/stdc++.h>
using namespace std;
//curr = balls,sharma=sum
bool find(long long int curr, long long int k) {
  long long int sum = 0, n = curr;
  while (n > 0) {
    long long int add = min(k, n);//this handles if n is less than k
    sum += add;//Mr. Sharma
    n -= add;
    n -= (n / 10);
  }
  return 2ll * sum >= curr;  
}

int main(){
   int t;
   cin>>t;
   while(t--){
       long long n;
       cin>>n;
       long long s = 1;
       long long e = n;
       long long ans = 0;
       
       while(s <= e){
           long long mid = (s+e)/2;
           long long balls = n;
           // int sharma = 0;          
//                                
 if (find(balls, mid)) 
 {
      ans = mid;
      e = mid - 1;
    }
  else
 {
    s = mid + 1;
  }                           
//                  
// while(balls > 0){
//     if(sharma >= n/2){
//         ans = mid;
//         e = mid-1;
//         break;
//     }
//     if(balls < mid){
//         ans = mid;
//         sharma = sharma+balls;
//         balls = 0;
//         break;
//     }
//     mid = min(mid,balls);
//     sharma = sharma+mid;
//     balls = (balls-mid);
//     int temp = balls/10;
//     balls = balls-temp;
// }         
           
// if(balls <= 0){    
//     ans = mid;
//     s = mid+1;
// }
                  
      
       }
      
       cout<<ans<<'\n';
  
   }

    return 0;
}


/*
long long helper(long long start, long long end, long long N, long long &ans){
	
	if (start > end)
	{
		return ans;
	}

	long long n = N;

	long long mid = (start+end)/2;
	
	long long k =  mid;


	long long sharma = 0, singh = 0;

	while(n>=k && n>0){
		sharma += k;
		n = n-k;
		singh += (n)/10;
		n = n-(n)/10;
	}

	sharma += n;
	if (2*sharma<N)	
	{
		return helper(mid+1, end, N, ans);
	}else{
		ans = k;
        return helper(start, mid-1, N, ans);
		
	}
}
        
  */      
        
/* Time complexity : O(log(N))
Space complexity : O(1) where N is the number of balls */
/*
#include <iostream>
using namespace std;
bool find(long long int curr, long long int k) {
  long long int sum = 0, n = curr;
  while (n > 0) {
    long long int add = min(k, n);//this handles if n is less than k
    sum += add;//Mr. Sharma
    n -= add;
    n -= (n / 10);
  }
  return 2ll * sum >= curr;
}
long long int bsearch(long long int n) {
  long long int ret = n / 2, lo = 1, hi = n;
  while (lo <= hi) {
    long long int mid = (lo + hi) / 2;
    if (find(n, mid)) {
      ret = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ret;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << (bsearch(n)) << endl;
  }
}
  */      
        
        
