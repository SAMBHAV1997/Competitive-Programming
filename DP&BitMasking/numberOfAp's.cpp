#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;
int m = pow(10,9)+7;
int numofAP(int *arr, int n)
{
    int ans=n+1;
    unordered_map<int, int>*map=new unordered_map<int, int>[n];
    //here this map will store that how many APs are their for this particular index with some particular common difference y
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int diff=arr[j]-arr[i];
            map[i/*on ith index*/][diff/*with this diff*/]+=1/*I have got one more AP*/;
            ans=(ans+1)%m;
        }
    }
    for(int i=n-3; i>=0; i--)
    {
        for(int j=i+1; j<n; j++)
        {
            int diff=arr[j]-arr[i];
            map[i][diff]=(map[i][diff]%m+map[j][diff]%m)%m;
            ans=(ans%m+map[j][diff]%m)%m;
        }
    }
    delete[]map;
    return ans;
}

int main(){
    // write your code here
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<numofAP(arr, n);
    return 0;
}


/* Time complexity: O(N*K) Space complexity: O(N) where N is the size of array
and K is the range of array values */
/*
#include <bits/stdc++.h> 
using namespace std; 
int mod = 1e9 + 7; 
int numofAP(int arr[], int n) { 
    int minElem = *min_element(arr, arr + n); 
    int maxElem = *max_element(arr, arr + n); 
    int totalAPs = n + 1; 
    int sum[1001];
    for (int d = (minElem - maxElem); d <= (maxElem - minElem); d++) {
        memset(sum, 0, sizeof(sum)); 
        for (int i = 0; i < n; i++) { 
            int a = 1;
            if (arr[i] - d >= 1 && arr[i] - d <= 1000)
                a = (a + sum[arr[i] - d]) % mod; 
            totalAPs = ((totalAPs + a - 1) % mod + mod) % mod; sum[arr[i]] = (sum[arr[i]] + a) % mod; } } 
    return totalAPs; }
int main() { 
    int n; 
    cin >> n; 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; } cout << numofAP(arr, n); }
        */
