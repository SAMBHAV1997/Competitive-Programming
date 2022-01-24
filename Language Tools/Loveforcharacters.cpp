#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[3]={0};
    unordered_map<char,int> a;
    for(int i = 0; s[i]; i++){
        a[s[i]] = a[s[i]]+1;
    }
    unordered_map<char, int>:: iterator it;
    for(it = a.begin(); it != a.end(); it++){
        if(it->first == 'a'){
        	arr[0] = it->second;    
        }else if(it->first == 's'){
            arr[1] = it->second;
        }else if(it->first == 'p'){
            arr[2] = it->second;
        }
    }
    for(int i = 0; i < 3; i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
