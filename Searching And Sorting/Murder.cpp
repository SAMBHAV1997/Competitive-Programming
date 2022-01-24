/*#include<bits/stdc++.h>
using namespace std;
//this code did'nt run because of using hashmaps

long long merge(int *input, int *output, int si, int ei, int mid){
    unordered_map<int, long long> a;
    long long sum = 0;
    for(int i = mid; i >= 0; i--){
        sum = sum + input[i];
        a[i] = a[i] + sum;
    }
    sum = 0;
    int i = si;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= ei){
        if(input[j] > input[i]){
            sum = sum + a[i];
            output[k] = input[j];
            j++;
            k++;
        }else{
            output[k] = input[i];
            i++;
            k++;
        }
    }
    while(i <= mid){
        output[k] = input[i];
        i++;
        k++;
    }
    while(j <= ei){
        output[k] = input[j];
        j++;
        k++;
    }
    for(int i=0;i<ei-si+1;i++){
        input[i+si] = output[i];
    }
    return sum;
}

long long mergesort(int *input, int si, int ei){
    if(si >= ei){
        return 0;
    }
    int mid = (ei+si)/2;
    long long leftI = mergesort(input, si, mid);
    long long rightI = mergesort(input, mid+1, ei);
    int* output = new int[ei-si+1]; 
    long long count = merge(input, output, si, ei, mid);
    delete[] output;
    return count+leftI+rightI;
}

long long murder(int *input, int n){
    int si = 0;
    int ei = n-1;
    return mergesort(input, si, ei);
}

int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* input = new int[n];
        for(int i = 0; i < n; i++){
            cin>>input[i];
        }
        long long ans = murder(input, n);
        cout<<ans<<'\n';
        delete[] input;
    }
    
    return 0;
}

*/

#include<iostream>

using namespace std;
typedef long long ll;

ll merge(ll *arr, ll left, ll mid, ll right)
{
	ll i=left;
	ll k=0;
	ll j=mid;
	ll sum=0;
	ll *temp=new ll [right-left+1];
	while(i<mid&&j<=right)
	{
		if(arr[i]<arr[j])
		{
			sum+=(arr[i]*(right-j+1));
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++]=arr[j++];
	}
	for(int i=left, k=0; i<=right; i++, k++)
	{
		arr[i]=temp[k];
	}
	delete[]temp;
	return sum;
}
ll merge_sort(ll *arr, ll left, ll right)
{
	ll count=0;
	if(right>left)
	{
		ll mid=(right+left)/2;
		ll left_count=merge_sort(arr, left, mid);
		ll right_count=merge_sort(arr, mid+1, right);
		ll merge_count=merge(arr, left, mid+1, right);
		
		return left_count+right_count+merge_count;
	}
	return count;
}
ll solve(ll *arr, ll n)
{
	ll ans=merge_sort(arr, 0, n-1);
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		//n== number of stairs;
		ll *arr=new ll [n];
		for(ll i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		cout<<solve(arr, n)<<endl;
	}
}
