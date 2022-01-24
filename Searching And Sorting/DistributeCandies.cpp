#include<bits/stdc++.h>
using namespace std;

int distribute_candies(int *arr, int n, int students){
    sort(arr, arr+n);
    int si = 0;
    int ei = arr[n-1];
    int mid = 0;
    int ans = 0;
    while(si <= ei){
        int temp = students;
        mid = (si+ei)/2;
        int i = 0;
        while(i < n){
        	int candies = arr[i];
        	while(candies >= mid){
            	temp--;
            	candies = candies-mid;
            	if(temp == 0){
                    ans = mid;
                	si = mid+1;
                    break;
            	}
        	}
        	i++;
        	if(temp == 0){
                ans = mid;
            	si = mid+1;
                break;
        	}
    	}
    	if(temp != 0){
        	ei = mid-1;
    	}
    }
    return ans;
}

int main(){
    // write your code
    int t;
	cin >> t;

	while (t--)
	{
		int n;
		int students;
		cin >> n;
		cin >> students;
		int *arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << distribute_candies(arr, n, students) << endl;

		delete[] arr;
	}
    
    return 0;
}
