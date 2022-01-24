#include<bits/stdc++.h>
#include<utility>
using namespace std;

#include<bits/stdc++.h>
#include<utility>
using namespace std;
bool cmp(pair<string,vector<int>> &a, pair<string,vector<int>> &b){
	int x =  a.second[0]+a.second[1]+a.second[2];
	int y = b.second[0]+b.second[1]+b.second[2];
    // agar marks same h toh, phir roll no ke hisab se sort kr do 
    if(x==y){
        return a.second[3] < b.second[3];
    }
    // marks ke hisab se sorting 
	return x > y;
}
int main()
{	
    int n;
    cin>>n;
    vector<pair<string,vector<int>>> v;
    for(int i = 0; i < n; i++){
        pair<string,vector<int>> p;
        cin>>p.first;
        for(int j = 0; j < 3; j++){
            int temp;
            cin>>temp;
            p.second.push_back(temp);
        }
        // yha pr maine ek roll no ke liye indexing add kr di 
        // because agar total marks same honge toh jiska roll no kam hoga usko 
        // preference milegi 
        p.second.push_back(i+1);
        v.push_back(p);
    }
    // calling normal sort function 
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        // printing according to 1 based indexing as given in the question 
        cout << i+1 << " " << v[i].first << endl;
    }
	return 0;
}
