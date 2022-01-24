#include<bits/stdc++.h>
using namespace std;

int place_cows(int *arr, int n, int cows){
    sort(arr, arr+n);
    int start = 0;
    int end = arr[n-1]-arr[0];
    int mid = 0;
    int ans = 1;					//line added
    while(start <= end){
        mid = (start + end)/2;
        int i = 0;
        int j = i+1;
        int temp = cows;
        
        while(j < n)
        {
            if(arr[j]-arr[i] >= mid)
            {
                i = j;
                j = i+1;
                temp--;
            }
            else
            {
                j++;
            }
            if(temp == 1)
            {
                ans = mid;			//line added
                start = mid+1;
                break;
            }
        }
        if(temp != 1)
        {
            end = mid-1;
        }
    }
    return ans;						//line edited
}

int main()
{
    int t;
	cin >> t;

	while (t--)
	{
		int n;
		int cows;
		cin >> n;
		cin >> cows;
		int *arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << place_cows(arr, n, cows) << endl;

		delete[] arr;
	}

    return 0;
}
