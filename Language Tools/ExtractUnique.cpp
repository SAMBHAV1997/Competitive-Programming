#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char, int> a;
    string answer;
  	for(int i = 0; i < str.length(); i++){
        if(a.count(str[i]) != 1){
            a[str[i]] = a[str[i]] + 1;
            answer.push_back(str[i]);
        }
    }
    return answer;
}
