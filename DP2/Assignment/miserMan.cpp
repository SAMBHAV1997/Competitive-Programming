#include<bits/stdc++.h>
using namespace std;
int miserMan(int** arr, int row, int col, int i, int j, int** dp){
    if(i == row){
        return 0;
    }
    if(dp[i][j] >-1){
        return dp[i][j];
    }   
    // int a = 0;
    // int b = 0;
    // int c = 0;
    // if(j >= 0){
    //     a = arr[i][j]+miserMan(arr, row, col, i+1, j-1, dp);
    // }
    // if(j < col){
    //     b = arr[i][j]+miserMan(arr, row, col, i+1, j+1, dp);
    // }
    // if(j >= 0 && j < col){
    //     c = arr[i][j]+miserMan(arr, row, col, i+1, j, dp);
    // }
    
    int a=arr[i][j]+miserMan(arr, row, col, i+1, j, dp);
	int b=INT_MAX;
	int c=INT_MAX;
    
	if(j+1<col)
	{
		b=arr[i][j]+miserMan(arr, row, col, i+1, j+1, dp);
	}
	if(j-1>=0)
	{
		c=arr[i][j]+miserMan(arr, row, col, i+1, j-1, dp);
	}
    
    int ans = min(a, min(b, c));
    dp[i][j] = ans;
    return ans;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int row;
        int col;
        cin>>row>>col;
        int** arr = new int*[row];
        for(int i = 0; i < row; i++){
            arr[i] = new int[col];
            for(int j = 0; j < col; j++){
                cin>>arr[i][j];
            }
        }
        int** dp = new int*[row+1];
        for(int i = 0; i <= row; i++){
            dp[i] = new int[col+1];
            for(int j = 0; j <= col; j++){
                dp[i][j] = -1;
            }
        }
        int minimum = INT_MAX;
        
     for(int bus=0; bus<col; bus++)
	{
		// for(int i=0; i<row+1; i++)
		// {
		// 	for(int j=0; j<col+1; j++)
		// 	{
		// 		dp[i][j]=-1;
		// 	}
		// }       
		// minimum=min(minimum, miserMan(arr, row, col, 0, bus, dp));
		minimum=min(minimum, miserMan(arr, row, col, 0, bus, dp));
         
	}
        cout<<minimum<<endl;
    }
    return 0;
}

/*
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int minimum_fare(int **arr, int n, int m, int i, int j, int **dp)
{
	if(i==n)
	{
		return 0;
	}
	if(dp[i][j]>=0)
	{
		return dp[i][j];
	}
	int option1=arr[i][j]+minimum_fare(arr, n, m, i+1, j, dp);
	int option2=INT_MAX;
	if(j+1<m)
	{
		option2=arr[i][j]+minimum_fare(arr, n, m, i+1, j+1, dp);
	}
	int option3=INT_MAX;
	if(j-1>=0)
	{
		option3=arr[i][j]+minimum_fare(arr, n, m, i+1, j-1, dp);
	}
	dp[i][j]= min(option1, min(option2, option3));
	return dp[i][j];
}
int main()
{
	int n, m;
	cin>>n>>m;
	int **arr=new int*[n];
	for(int i=0; i<n; i++)
	{
		arr[i]=new int [m];
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int **dp=new int *[n+1];
	for(int i=0; i<n+1; i++)
	{
		dp[i]=new int [m+1];
	}
	
	int minimum=INT_MAX;
	for(int bus=0; bus<m; bus++)
	{
		for(int i=0; i<n+1; i++)
		{
			for(int j=0; j<m+1; j++)
			{
				dp[i][j]=-1;
			}
		}
		minimum=min(minimum, minimum_fare(arr, n, m, 0, bus, dp));
	}
    for(int i=0; i<n+1; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
	cout<<minimum<<endl;
}*/
