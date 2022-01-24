#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    int maxl = 0;
    int startI = 0;
    unordered_map<int, int> a1;
    unordered_map<int, bool> a2;
    for(int i = 0; i < n; i++){
        a1[arr[i]] = i;
        a2[arr[i]] = true;
    }
    for(int i = 0; i < n; i++){
        if(a2[arr[i]] == true){
            a2[arr[i]] = false;
            int len = 0;
            int index = i;
            int j = 1;
            while(a1.count(arr[i]-j) == 1){
                a2[arr[i]-j] = false;
                len++;
                index = a1[arr[i]-j];
                j++;
            }
            j = 1;
            while(a1.count(arr[i]+j) == 1){
                a2[arr[i]+j] = false;
                len++;
                j++;
            }
            if(maxl < len){
                maxl = len;
                startI = index;
            }else if(maxl == len){
                if(startI > index){
                    startI = index;
                }
            }
        }
    }
    int temp = arr[startI];
    vector<int> v;
    for(int i = 0; i <= maxl; i++){
        v.push_back(temp);
        temp++;
    }
    return v;
    
}
