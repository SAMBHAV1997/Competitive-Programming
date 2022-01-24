/*#include<bits/stdc++.h>
using namespace std;
//index = returning new word;
char crossword[10][10];

bool isValidVertical(string temp, int row, int col){
    int len = 0;
	for(int i = row; i < 10; i++){
        if(crossword[i][col] == '-' || crossword[i][col] == temp[len]){
            len++;
        }else{
            if(len == temp.size()){
                return true;
            }else{
                return false;
            }
        } 
    }
    if(len == temp.size()){
        return true;
    }else{
        return false;
    }
    
}

bool isValidHorizontal(string temp, int row, int col){
    int len = 0;
	for(int i = col; i < 10; i++){
        if(crossword[row][i] == '-' || crossword[row][i] == temp[len]){
            len++;
        }else{
            if(len == temp.size()){
                return true;
            }else{
                return false;
            }
        } 
    }
    if(len == temp.size()){
        return true;
    }else{
        return false;
    }
}

void setVertical(bool* arr, string temp, int row, int col){
    int k = 0;
    for(int i = row; i < temp.size(); i++){
        if(crossword[i][col] == '-'){
            arr[k] = true;
            crossword[i][col] = temp[k];
            k++;
        }else{
            arr[k] = false;
            k++;
        }
    }
}

void setHorizontal(bool* arr, string temp, int row, int col){
    int k = 0;
    for(int i = col; i < temp.size(); i++){
        if(crossword[row][i] == '-'){
            arr[k] = true;
            crossword[row][i] = temp[k];
            k++;
        }else{
            arr[k] = false;
            k++;
        }
    }
}

void resetVertical(bool* arr, string temp, int row, int col){
    int k = 0;
    for(int i = row; i < temp.size(); i++){
        if(arr[k]){
            crossword[i][col] = '-';
        }
        k++;
    }
}

void resetHorizontal(bool* arr, string temp, int row, int col){
    int k = 0;
    for(int i = row; i < temp.size(); i++){
        if(arr[k]){
            crossword[i][col] = '-';
        }
        k++;
    }
}

bool puzzle(string words, int index){
    if(words.empty()){
        //print crossword
    	for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    string temp;
    for(int i = 0; i < words.size(); i++){
        if(words[i] == ';'){
            temp = words.substr(0,i-1);
            words = words.substr(i);
            break;
        }
    }
    index = temp.size()+1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(crossword[i][j] == '-' || crossword[i][j] == temp[0]){
                 bool *arr = new bool[temp.size()];
                 if(isValidVertical(temp, i, j)){
                      setVertical(arr, temp, i, j);
                      // puzzle(words, index+1);
                      // resetVertical(arr, temp, i , j);
                      if(puzzle(words, index+1)){
                      	return true;    
                      }else{
                          resetVertical(arr, temp, i, j);
                          return false;
                      }
                 }else if(isValidHorizontal(temp, i, j)){
                     setHorizontal(arr, temp, i, j);
                     //puzzle(words, index+1);
                     //resetHorizontal(arr, temp, i, j);
                     if(puzzle(words, index+1)){
                     	return true;    
                     }else{
                    	 resetHorizontal(arr, temp, i, j);
                     	 return false;
                     }
                 }
            }
        }
    }
}

int main(){
    
    // write your code here
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin>>crossword[i][j];
        }
        //cin>>endl;
    }
    string words;
    cin>>words;
    //index = 0;
    bool a = puzzle(words, 0);
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
//index = returning new word;
char crossword[10][10];

bool isValidVertical(string temp, int row, int col){
    // cout<<"here3"<<endl;
    int len = 0;
	for(int i = row; i < 10; i++){
        if(crossword[i][col] == '-' || crossword[i][col] == temp[len]){
            len++;
        }else{
            if(len == temp.size()){
                return true;
            }else{
                return false;
            }
        } 
    }
    if(len == temp.size()){
        return true;
    }else{
        return false;
    }
    
}

bool isValidHorizontal(string temp, int row, int col){
    
    int len = 0;
	for(int i = col; i < 10; i++){
        if(crossword[row][i] == '-' || crossword[row][i] == temp[len]){
            len++;
        }else{
            if(len == temp.size()){
                return true;
            }else{
                return false;
            }
        } 
    }
    if(len == temp.size()){
        return true;
    }else{
        return false;
    }
}

void setVertical(bool* arr, string temp, int row, int col){
    
    //cout<<"vertical "<<temp<<endl;
    int k = 0;
    for(int i = row; i < temp.size()+row; i++){
        if(crossword[i][col] == '-'){
            arr[k] = true;
            crossword[i][col] = temp[k];
            k++;
        }else{
            arr[k] = false;
            k++;
        }
    }
}

void setHorizontal(bool* arr, string temp, int row, int col){
    
    //cout<<"horizontal "<<temp<<endl;
    
    int k = 0;
    for(int i = col; i < temp.size()+col; i++){
        if(crossword[row][i] == '-' ){
            arr[k] = true;
            crossword[row][i] = temp[k];
            k++;
        }else{
            arr[k] = false;
            k++;
        }
    }
}

void resetVertical(bool* arr, string temp, int row, int col){
    int k = 0;
    for(int i = row; i < temp.size()+row; i++){
        if(arr[k]){
            crossword[i][col] = '-';
        }
        k++;
    }
}

void resetHorizontal(bool* arr, string temp, int row, int col){
    int k = 0;
    for(int i = col; i < temp.size()+col; i++){
        if(arr[k]){
            crossword[row][i] = '-';
        }
        k++;
    }
}

bool puzzle(string words, int index){
    if(words.length()==0){
        //print crossword
    	for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    string temp = "";
    for(int i = 0; i < words.size(); i++){
        if(words[i] == ';'){
            temp = words.substr(0,i);
            words = words.substr(i+1);
            break;
        }
    }
    if(temp.length()==0){
        temp = words;
        words = "";
    }
    // cout<<temp<<endl;
    index = temp.size()+1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(crossword[i][j] == '-' || crossword[i][j] == temp[0]){
                 bool *arr = new bool[temp.size()];
                 if(isValidVertical(temp, i, j)){
                      setVertical(arr, temp, i, j);
                      // puzzle(words, index+1);
                      // resetVertical(arr, temp, i , j);
                      if(puzzle(words, index+1)){
                      	return true;    
                      }else{
                          resetVertical(arr, temp, i, j);
                      }
                 }
                 if(isValidHorizontal(temp, i, j)){
                     setHorizontal(arr, temp, i, j);
                     //puzzle(words, index+1);
                     //resetHorizontal(arr, temp, i, j);
                     if(puzzle(words, index+1)){
                     	return true;    
                     }else{
                    	 resetHorizontal(arr, temp, i, j);
                     }
                 }
            }
        }
    }
    
    return false;
}

int main(){
    
    // write your code here
    for(int i = 0; i < 10; i++){
        cin>>crossword[i];
        //cin>>endl;
    }
    string words;
    cin>>words;
    //index = 0;
    bool a = puzzle(words, 0);
    return 0;
}
