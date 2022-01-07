#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}


int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        pair<int, int> p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), sortbysec);
    int ans = 1;
    int s = v[0].first;
    int e = v[0].second;
    for(int i = 0; i < n; i++){
        if(v[i].first >= e){
            ans++;
            e = v[i].second;
        }
    }
    cout<<ans;
    // write your code here
    return 0;
}
