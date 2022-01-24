#include<bits/stdc++.h>
using namespace std;
/*
unordered_map<int, pair<int,int>> momos_market(int* arr, int n, int * query, int q){
    unordered_map<int, pair<int,int>> a;
    sort(query, query+q);
    int i = 0;
    int shops = 0;
    int balance = 0;
    int j = 0;
    int temp = query[j];
    while(j < q){
        balance = 0;
    	while(i < n){
        	if(temp >= arr[i]){
                temp = temp-arr[i];
                shops++;
                i++;
            }else{
                balance = temp;
                a[query[j]].first = shops;
                a[query[j]].second = balance;
                break;
            }
    	}
        temp = balance+query[j+1]-query[j];
        j++;
    }
    return a;
}

int main(){
    // write your code
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    int *query = new int[q];
    for(int i = 0; i < q; i++){
        cin>>query[i];
    }
    unordered_map<int,pair<int,int>> a = momos_market(arr, n, query, q);
    for(int i = 0; i < q; i++){
        cout<<a[query[i]].first<<" "<<a[query[i]].second<<'\n';
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long

void momos_market(int* arr, int n, int * query, int q){
    unordered_map<int,int> mp;
    for(int i=0;i<q;i++)
    {
        mp[query[i]] = i;
    }
    vector<pair<int,int>> ans(q);
    sort(query, query+q);
    int i = 0;
    int shops = 0;
    int balance = 0;
    int j = 0;
    int temp = query[j];
    while(j < q)
    {
        balance = 0;
    	while(i < n)
        {
        	if(temp >= arr[i])
            {
                temp = temp-arr[i];
                shops++;
                i++;
                // cout<<shops<<" ";
            }
            else
            {
                balance = temp;
                
                // cout<<shops<<" "<<balance<<'\n';
                break;
            }
    	}
        ans[mp[query[j]]] = {shops,balance};
        temp = balance+query[j+1]-query[j];
        
        j++;
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}

signed main(){
    // write your code
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    int *query = new int[q];
    
    for(int i = 0; i < q; i++){
        cin>>query[i];
    }
    momos_market(arr, n, query, q);
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

int search(long arr[], int low, int high, long x) {
    if(low>high) {
        return -1;
    }
    if(x>=arr[high]) {
        return high;
    }
    int mid=(low+high)/2;
    if(arr[mid]==x) { 
        return mid;
    } 
    if(mid>0 && arr[mid-1]<=x && x<arr[mid]) { 
        return mid-1;
    }
    if(x<arr[mid]) {
        return search(arr,low,mid-1,x);
    }
    return search(arr,mid+1,high,x);
}
int main() { 
    int n;
    cin>>n;
    long* arr=new long[n]; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i];
    } 
    long* prefix=new long[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++) {
        prefix[i]=prefix[i-1]+arr[i];
    }
    int q;
    cin>>q;
    while(q-->0) {
        long x;
        cin>>x;
        int s=search(prefix,0,n-1,x); 
        long val=x;
        if(s!=-1) { 
            val-=prefix[s];
        }
        cout<<s+1<<" "<<val<<endl;
    }
}
