#include<bits/stdc++.h>
using namespace std;

struct item{
	int value,weight;    
};

bool compare(struct item a, struct item b){
    double value1 = (double)a.value/a.weight;
    double value2 = (double)b.value/b.weight;
    
    return value1 > value2;
}

double fractionalKnapsack(struct item arr[], int n, int W){
    int curW = 0;
    double profit = 0;
    for(int i = 0; i < n; i++){
        if(curW + arr[i].weight <= W){
            curW += arr[i].weight;
            profit += arr[i].value;
        }else{
            int remainingW = W-curW;
            profit += arr[i].value * ((double)remainingW/arr[i].weight);
            break;
        }
    }
    return profit;
}

int main(){
    int n,W;
    cin>>n>>W;
    item arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i].value>>arr[i].weight;
    }
    sort(arr, arr+n, compare);//sort the array on the basis of value/weight ratio
    std::cout << std::fixed;
    std::cout << std::setprecision(6)<<fractionalKnapsack(arr, n, W)<<endl;
    // write your code here
    return 0;
}



