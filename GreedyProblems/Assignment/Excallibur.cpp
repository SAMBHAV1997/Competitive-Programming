#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin>>n;
		vector<int>a(n+1);
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		sort(a.begin()+1,a.end());

		vector<int>dp(n+1,0);

		int ans = 0;
		for(int i=1;i<=n;++i){
			if(i - a[i] >= 0) {
				dp[i] = max(dp[i-1], dp[i-a[i]] + 1);
			}else{
				dp[i] = dp[i-1];
			}
		}

		cout<<dp[n]<<endl;
	}
	return 0;
}
