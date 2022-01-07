#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        int* arrs = new int[n+1];
        int* arre = new int[n+1];
        for(int i = 1; i <= n; i++){
            arrs[i] = 0;
            arre[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int start = 0;
            int end = 0;
            cin>>start>>end;
            arrs[start] += 1;
            arre[end] += 1;
        }
        int* kcoins = new int[n+1];
        kcoins[1] = arrs[1];
        for(int i = 2; i <= n; i++){
            kcoins[i] = arrs[i] + kcoins[i-1] - arre[i-1];
        }
        int* nboxes = new int[n+1];
        int* atleastX = new int[n+1];
        for(int i = 1; i <= n; i++){
            nboxes[i] = 0;
            atleastX[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            nboxes[kcoins[i]] += 1;
        }
        atleastX[n] = nboxes[n];
        for(int i = n-1; i > 0; i--){
            atleastX[i] = nboxes[i] + atleastX[i+1];
        }
        int Q;
        cin>>Q;
        for(int i = 1; i <= Q; i++){
            int x;
            cin>>x;
            cout<<atleastX[x]<<endl;
        }
    }
    return 0;
}
