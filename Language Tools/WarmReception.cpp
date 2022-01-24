#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin>>n;
    int arrival[n];
    int departure[n];
    for(int i = 0; i < n; i++){
        cin>>arrival[i];
    }
    for(int i = 0; i < n; i++){
        cin>>departure[i];
    }
	sort(arrival, arrival + n);
    sort(departure, departure + n);
    int i = 0;
    int j = 0;
    int chair = 0;
    int max = 0;
    while(i < n || j < n){
        if(arrival[i] < departure[j]){
            i++;
            chair++;
        }else{
            j++;
            chair--;
        }
        if(max < chair){
            max = chair;
        }
    }
    cout<<max;
    
    
    
}
