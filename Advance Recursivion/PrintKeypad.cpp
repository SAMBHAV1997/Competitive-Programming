#include <iostream>
#include <string>
using namespace std;

void helper(int num, string output, string arr[]){
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    string smallString = arr[num%10];
    for(int i = 0; i < smallString.size(); i++){
        helper(num/10, smallString[i]+output, arr);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
	string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output;
    helper(num, output, arr);
    
}
