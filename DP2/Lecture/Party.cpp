#include<bits/stdc++.h>
using namespace std;
pair<int, int> partyR(int* arrw, int* arrv, pair<int, int>** dp, int n, int wt){
    if(n == 0 || wt == 0){
        pair<int, int> a = make_pair(0,0);
        return a;
    }
    if(dp[n][wt].first > -1 && dp[n][wt].second > -1){
        return dp[n][wt];
    }
    pair<int, int> x = make_pair(0,0);
    pair<int, int> ans = make_pair(0,0);
    if(arrw[n-1] <= wt){
		x = partyR(arrw, arrv, dp, n-1, wt-arrw[n-1]);
        x.first += arrw[n-1];
        x.second += arrv[n-1];
    }
    pair<int, int> y = partyR(arrw, arrv, dp, n-1, wt);
    //x.first += arrw[n-1];
    //x.second += arrv[n-1];
    if(x.second > y.second){
        ans.first = x.first;
        ans.second = x.second;
    }else if(y.second > x.second){
        ans.first = y.first;
        ans.second = y.second;
    }else{
        if(x.first < y.first){
        	ans.first = x.first;
            ans.second = x.second;
        }else{
            ans.first = y.first;
        	ans.second = y.second;
        }
    }
    //ans = max(x.second,y.second);
    dp[n][wt] = ans;
    return ans;
    
    
}

int main(){
    // write your code here
    int n;
    cin>>n;
    int* arrw = new int[n];
    int* arrv = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arrw[i];
    }
    for(int i = 0; i < n; i++){
        cin>>arrv[i];
    }
    int wt;
    cin>>wt;
    pair<int, int>** dp = new pair<int, int>*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new pair<int,int>[wt+1];
        for(int j = 0; j <= wt; j++){
            dp[i][j] = make_pair(-1,-1);
        }
    }
    //knapsackI(arrw, arrv, dp, n, wt);
    pair<int,int> a = partyR(arrw, arrv, dp, n, wt);
    cout<<a.first<<" "<<a.second;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

void knapsack(int* arrw, int* arrv, int** dp, int n, int wt){
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= wt; j++){
        dp[0][j] = 0;
    }
    int dp2[n+1][wt+1]={0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= wt; j++){
            dp[i][j] = dp[i-1][j];
            dp2[i][j]=dp2[i-1][j];
            if(arrw[i-1] <= j){
                int temp=arrv[i-1]+dp[i-1][j-arrw[i-1]];
                if(dp[i][j]<temp)
                {
                    dp[i][j]=temp;
                    dp2[i][j]=arrw[i-1]+dp2[i-1][j-arrw[i-1]];
                }
            }
        }
    }
    cout<<dp2[n][wt]<<" "<<dp[n][wt];
}

int main(){
    // write your code here
    int n;
    cin>>n;
    int* arrw = new int[n];
    int* arrv = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arrw[i];
    }
    for(int i = 0; i < n; i++){
        cin>>arrv[i];
    }
    int wt;
    cin>>wt;
    int** dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[wt+1];
    }
    knapsack(arrw, arrv, dp, n, wt);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,x,y,pb,j;
	
	
	cin >> n;
	
    pair<int,int>pf[n];
    
	for(i=0;i<n;i++)
        cin >> pf[i].first;
	for(i=0;i<n;i++)
        cin >> pf[i].second;
    
    cin >> pb;
    
	int dp[n+1][pb+1];
    
	for(i=0;i<=n;i++)
		for(j=0;j<=pb;j++)
			dp[i][j]=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=pb;j++)
			if(pf[i-1].first<=j)
				dp[i][j]=max(pf[i-1].second+dp[i-1][j-pf[i-1].first],dp[i-1][j]);
			else 
				dp[i][j]=dp[i-1][j];
	
	int maxfun=dp[n][pb];
	int minmoney=0;
	for(i=0;i<=pb;i++)
	{
		if(dp[n][i]==maxfun)
		{
			minmoney=i;
			break;
		}
	}
	printf("%d %d\n",minmoney,maxfun);

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;


pair<int,int> solve(int * ent_fee,int *fun,int i,int budget)
{
    if(budget==0||i==0)
    {
        pair<int,int> a=make_pair(0,0);
        return a;
    }
    
    if(ent_fee[i-1]>budget)
    {
        return solve(ent_fee,fun,i-1,budget);
    }
    

    pair<int,int> a=solve(ent_fee,fun,i-1,budget-ent_fee[i-1]);
    pair<int,int> b=solve(ent_fee,fun,i-1,budget);
    a.first+=ent_fee[i-1];
    a.second+=fun[i-1];
    
    if(a.second>b.second)
    {
        return a;
    }
    if(b.second>a.second)
    {
        return b;
    }
    if(a.first<b.first)
    {
        return a;
    }
    return b;
    
}

int main(){
    
    int n,budget;
    cin>>n;
    int ent_fee[n],fun[n];
    for(int i=0;i<n;i++)
    {
        cin>>ent_fee[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>fun[i];
    }
    cin>>budget;
    /*pair<int,int> ans=solve(ent_fee,fun,n,budget);
    cout<<ans.first<<" "<<ans.second<<endl;
    
    
    pair<int,int> dp[n+1][budget+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=make_pair(0,0);
    }
    for(int i=0;i<=budget;i++)
    {
        dp[0][i]=make_pair(0,0);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=budget;j++)
        {
            if(ent_fee[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                pair<int,int> a=dp[i-1][j-ent_fee[i-1]];
                pair<int,int> b=dp[i-1][j];
                
                a.first+=ent_fee[i-1];
                a.second+=fun[i-1];
                if(a.second>b.second)
                {
                    dp[i][j]=a;
                }
                else if(b.second>a.second)
                {
                    dp[i][j]=b;
                }
                else
                {
                    if(a.first<b.first)
                    {
                        dp[i][j]=a;
                    }
                    else
                    {
                        dp[i][j]=b;
                    }
                        
                }
            }
            
        }
    }
    cout<<dp[n][budget].first<<" "<<dp[n][budget].second<<endl;
    return 0;
}*/
