#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Write your code here
    bool flag = false;
    //string s = '\0';
    unordered_map<string, int> a;
    string str;
    getline(cin,str);
    for(int i = 0; str[i]; i++){
         //s = '\0';
         int j = i;
         while(str[j] != ' ' && str[j] != '\0'){
             //s.push_back(str[j]);
             j++;
         }
         string s = 
         i = j;
         a[s] = a[s]+1;
    }
    unordered_map<string, int> :: iterator it;
    for(it = a.begin(); it != a.end(); it++){
        if(it->second > 1){
            cout<<it->first<<" "<<it->second;
            cout<<endl;
            flag = true;
        }
    }
    if(flag == false){
        cout<<-1;
    }
}



