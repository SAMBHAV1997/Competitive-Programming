/*#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        int** arr = new int*[n+1];
        for(int i = 1; i <= n; i++){
            arr[i] = new int[m+1];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>arr[i][j];
            }
        }
        int** dp = new int*[n+1];
        for(int i = 1; i <=n; i++){
            dp[i] = new int[m+1];
            //dp[i] = i;
        }
        for(int i = 1; i <= m; i++){
            dp[1][i] = 1;
        }
    	for(int i = 2; i <= m; i++){
            for(int j = 1; j <= n; j++){
            	if(arr[j][i] > arr[j-1][i]){
                	dp[j][i] = dp[j-1][i];   		    
                }else{
                    dp[j][i] = j;
                }
            }
        }
        int* ans = new int[n+1];
        ans[1] = 1;
        for(int i = 2; i <= n; i++){
            int min = INT_MAX;
            for(int j = 1; j <= m; j++){
                if(dp[i][j] < min){
                    min = dp[i][j];
                }
            }
            ans[i] = min;
        }
        int Q;
        cin>>Q;
        for(int i = 1; i <= Q; i++){
            int start;
            int end;
            cin>>start>>end;
            if(ans[end] >= start){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        int** arr = new int*[n+1];
        for(int i = 0; i <= n; i++){
            arr[i] = new int[m+1];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>arr[i][j];
            }
        }
        int** dp = new int*[n+1];
        for(int i = 0; i <=n; i++){
            dp[i] = new int[m+1];
            //dp[i] = i;
        }
        // for(int i = 1; i <= m; i++){
        //     dp[1][i] = 1;
        // }
    	for(int i = 1; i <= m; i++){
            dp[0][i]=0;
            for(int j = 2; j <= n; j++){
            	if(arr[j][i] >= arr[j-1][i]){
                	dp[j][i] = dp[j-1][i];   		    
                }else{
                    dp[j][i] = j;
                }
            }
        }
        int* ans = new int[n+1];
        ans[1] = 1;
        for(int i = 2; i <= n; i++){
            int min = INT_MAX;
            for(int j = 1; j <= m; j++){
                if(dp[i][j] < min){
                    min = dp[i][j];
                }
            }
            ans[i] = min;
        }
        int Q;
        cin>>Q;
        for(int i = 1; i <= Q; i++){
            int start;
            int end;
            cin>>start>>end;
            if(ans[end] <= start){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
