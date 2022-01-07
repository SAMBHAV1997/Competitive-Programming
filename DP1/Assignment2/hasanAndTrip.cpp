#include<bits/stdc++.h>
using namespace std;

double distance(int i, int j, int* arrx, int* arry){
    double x1 = arrx[i];
    double y1 = arry[i];
    double x2 = arrx[j];
    double y2 = arry[j];
    double difx = x2-x1;
    double dify = y2-y1;
    double ans = sqrt((difx*difx) + (dify*dify));
    return ans;
}

double hasanTrip(int* arrx, int* arry, int* arrh, int n){
	double* dp = new double[n];
    dp[0] = arrh[0];
    for(int i = 1; i < n; i++){
        dp[i] = INT_MIN;
        for(int j = i-1; j >= 0; j--){
            dp[i] = max(dp[i], dp[j]-distance(i, j, arrx, arry));
        }
        dp[i] += arrh[i];
    }
    return dp[n-1];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arrx = new int[n];
        int* arry = new int[n];
        int* arrh = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arrx[i]>>arry[i]>>arrh[i];
        }
        cout<<fixed << setprecision(6) << hasanTrip(arrx, arry, arrh, n)<<endl;
        //cout<<hasanTrip(arrx, arry, arrh, n)<<endl;
    }
    return 0;
}
