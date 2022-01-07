/*#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start, finish, profit;
};

bool compare(struct Job a, struct Job b){
    return a.finish < b.finish;
}

int maxProfit(Job arr[], int n){
    int* dp = new int[n];
    dp[0] = arr[0].profit;
    //int ans = 0;
    //int s = arr[0].start;
    //int e = arr[0].finish;
    for(int i = 1; i < n; i++){
        dp[i] = arr[i].profit;
        int nonConflict = -1;
        for(int j = i-1; j >= 0; j--){
            if(arr[j].finish <= arr[i].start){
                dp[i] += dp[j];
                break;
            }
        }
        dp[i] = max(dp[i-1], dp[i]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    Job arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    sort(arr, arr+n, compare);
    cout<<maxProfit(arr, n);
    // write your code here
    return 0;
}*/


#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start, finish, profit;
};

bool compare(struct Job a, struct Job b){
    return a.finish < b.finish;
}

int binarySearch(Job *arr, int n, int r){
	int left = 0;
	int right = r - 1;
	while(left <= right){
		int mid = (left + right)/2;
		if(arr[mid].finish <= arr[r].start){
			if(arr[mid + 1].finish <= arr[r].start){
				left = mid + 1;
			}
			else
				return mid;
		}
		else
			right = mid - 1;
	}
	return -1;
}

int maxProfit(Job arr[], int n){
    int* dp = new int[n];
    dp[0] = arr[0].profit;
    for(int i = 1; i < n; i++){
        dp[i] = arr[i].profit;
        int nonConflict = -1;
        nonConflict= binarySearch(arr, n, i);
        if(nonConflict != -1){
            dp[i] += dp[nonConflict];
        }
        dp[i] = max(dp[i-1], dp[i]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    Job arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    sort(arr, arr+n, compare);
    cout<<maxProfit(arr, n);
    // write your code here
    return 0;
}
