#include<bits/stdc++.h>
using namespace std;
/*
int magicGrid(int** arr, int** dp, int row, int col){
    dp[row-1][col-1] = 1;
    dp[row-2][col-1] = 1;
    dp[row-1][col-2] = 1;
    for(int i = col-3; i >= 0; i--){
        if((dp[row-1][i+1] - arr[row-1][i]) > 1){
        	dp[row-1][i] = dp[row-1][i+1] - arr[row-1][i];
        }else{
            dp[row-1][i] = 1;
        }
    }
    for(int i = row-3; i >= 0; i--){
        if((dp[i+1][col-1] - arr[i][col-1]) > 1){
        	dp[i][col-1] = dp[i+1][col-1] - arr[i][col-1];
        }else{
            dp[i][col-1] = 1;
        }
    }
    for(int i = row-2; i >= 0; i--){
        for(int j = col-2; j >= 0; j--){
            if((min((dp[i][j+1] - arr[i][j]) , (dp[i+1][j] - arr[i][j]))) > 1){
            	dp[i][j] = min((dp[i][j+1] - arr[i][j]) , (dp[i+1][j] - arr[i][j]));
            }else{
                dp[i][j] = 1;
            }
        }
    }
    return dp[0][0];
}
*/

int magicGrid(int** arr, int** dp, int r, int c){
    dp[r-1][c-1] = 1;
    for(int i = r-2; i >= 0; i--)
    {
        dp[i][c-1] = max(1, dp[i+1][c-1] - arr[i+1][c-1]);
    }
    for(int j = c-2; j >= 0; j--)
    {
        dp[r-1][j] = max(1, dp[r-1][j+1] - arr[r-1][j+1]);
    }
    
    for(int i = r-2; i >= 0; i--)
    {
        for(int j = c-2; j >= 0; j--)
        {
            int down = dp[i+1][j] - arr[i+1][j];
            int right = dp[i][j+1] - arr[i][j+1];
            dp[i][j] = max(1, min(down, right));
        }
    }
    return dp[0][0];
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int row;
        cin>>row;
        int col;
        cin>>col;
        int** arr = new int*[row];
        for(int i = 0; i < row; i++){
            arr[i] = new int[col];
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin>>arr[i][j];
            }
        }
        int** dp = new int*[row];
        for(int i = 0; i < row; i++){
            dp[i] = new int[col];
        }
        cout<<magicGrid(arr, dp, row, col)<<endl;
    }
    return 0;
}
