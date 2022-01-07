#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll fun_(vector<pair<ll, ll>> &temp, int index, int n) {
    bool vis[n]; 
    memset(vis, false, sizeof(vis));
    ll a = 0, cost = 0; 
    while (a < n) 
    { cost += temp[index].first;
     ll b = temp[index].second; 
     index++; 
     index = (n + index) % n; 
     temp[index].first = max(0ll, temp[index].first - b);
     a++; } return cost; }
int main() { 
    int t; 
    cin >> t; 
    while (t--) { 
        int n; 
        cin >> n; 
        ll a = 0, c, d; 
        vector<pair<ll, ll>> arr;
        for (int i = 0; i < n; i++)
        { cin >> c >> d; 
         arr.push_back({c, d}); } 
        vector<pair<ll, ll>> store;
        c = arr[n - 1].second;
        for (int i = 1; i < n; i++) { 
            ll f = arr[i].first + arr[0].first - min(arr[0].first, arr[n - 1].second);
            ll g = arr[0].first + arr[i].first - min(arr[i].first, arr[i - 1].second); 
            store.push_back({f - g, i}); } sort(store.begin(), store.end()); 
        if (store.size() > 0 && store[0].first < 0) { 
            a = store[0].second; } 
        else a = 0;
        ll ans = fun_(arr, a, n); cout << ans << endl; } }
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            pair<int, int> p;
            cin>>p.first>>p.second;
            v.push_back(p);
        }
        int* arr = new int[n];
        int temp = v[0].first - v[n-1].second;
        if(temp < 0){
            arr[0] = 0;
        }else{
            arr[0] = temp;
        }
        for(int i = 1; i < n; i++){
            if((v[i].first - v[i-1].second) < 0){
                arr[i] = 0;
            }else{
                arr[i] = temp;
            }
        }
        int* minArr = new int[n];
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                minArr[i] = v[i].first;
            }else{
                minArr[i] = v[i].first-arr[i];
            }
        }
        int min = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(min > minArr[i]){
                min = minArr[i];
            }
            ans = ans+arr[i];
        }
        ans = ans+min;
        cout<<ans<<endl;
    }
    // write your code here
    return 0;
}*/
