/*#include<bits/stdc++.h>
using namespace std;

int sudoku[9][9];

pair<int, int> box(int row, int col){
    pair<int, int> temp;
    if(row <= 2){
        temp.first = 0;
    }else if(row <= 5){
        temp.first = 3;
    }else if(row <= 8){
        temp.first = 6;
    }
    
    if(col <= 2){
        temp.second = 0;
    }else if(col <= 5){
        temp.second = 3;
    }else if(col <= 8){
        temp.second = 6;
    }
    return temp;
}

vector<int> alloptions(int row, int col){
    vector<int> v;
    pair<int, int> p = box(row,col);
    int sr = p.first;
    int sc = p.second;
    unordered_map<int, int> a;
    //box
    for(int i = sr; i < sr+3; i++){
        for(int j = sc; j < sc+3; j++){
            if(sudoku[i][j] != 0){
            	a[sudoku[i][j]] += 1;
            }
        }
    }
    //row
    for(int i = 0; i < 9; i++){
        if(sudoku[row][i] != 0){
            a[sudoku[row][i]] += 1; 
        }
    }
    //column
     for(int i = 0; i < 9; i++){
        if(sudoku[i][col] != 0){
            a[sudoku[i][col]] += 1; 
        }
    }
    
    for(int i = 1; i <= 9; i++){
        if(a.count(i) != 1){
            v.push_back(i);
        }
    }
    
    return v;
}

bool sudoku_solver(int row, int col){
	if(row == 9 && col == 9){
    	return true;
    }
    
for(int i = row; i < 9; i++){
  for(int j = col; j < 9; j++){      
	if(sudoku[i][j] == 0){
        vector<int> options = alloptions(i,j);
        if(options.size()==0){
            //backtrack
            return false;
        }else{
            sudoku[i][j] = options.back();
         	if(col < 9){
                if(sudoku_solver(row, col+1)){
                    true;
                }else{
                    options.pop_back();
                    if(options.size() != 0){
                    	sudoku[i][j] = options.back();
                    }else{
                        sudoku[i][j] = 0;
                        return false;
                    }
                }
            }else{
                if(sudoku_solver(row+1, 0)){
                    true;
                }else{
                    options.pop_back();
                    if(options.size() != 0){
                    	sudoku[i][j] = options.back();
                    }else{
                        sudoku[i][j] = 0;
                        return false;
                    }
                }
            }
        }
    }
  }
}
}

int main(){
    
    // write your code here
    for(int i = 0; i < 9; i++){
    	for(int j = 0; j < 9; j++){
        	cin>>sudoku[i][j];
        }
    }
	bool a = sudoku_solver(0,0);
    if(a){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

int sudoku[9][9];

pair<int, int> box(int row, int col){
    pair<int, int> temp;
    if(row <= 2){
        temp.first = 0;
    }else if(row <= 5){
        temp.first = 3;
    }else if(row <= 8){
        temp.first = 6;
    }

    if(col <= 2){
        temp.second = 0;
    }else if(col <= 5){
        temp.second = 3;
    }else if(col <= 8){
        temp.second = 6;
    }
    return temp;
}

vector<int> alloptions(int row, int col){
    vector<int> v;
    pair<int, int> p = box(row,col);
    int sr = p.first;
    int sc = p.second;
    unordered_map<int, int> a;
    //box
    for(int i = sr; i < sr+3; i++){
        for(int j = sc; j < sc+3; j++){
            if(sudoku[i][j] != 0){
            a[sudoku[i][j]] += 1;
            }
        }
    }
    //row
    for(int i = 0; i < 9; i++){
        if(sudoku[row][i] != 0){
            a[sudoku[row][i]] += 1;
        }
    }
    //column
     for(int i = 0; i < 9; i++){
        if(sudoku[i][col] != 0){
            a[sudoku[i][col]] += 1;
        }
    }

    for(int i = 1; i <= 9; i++){
        if(a.count(i) != 1){
            v.push_back(i);
        }
    }
    return v;
}

bool sudoku_solver(int row, int col){
    if(row >=9 ){
    	return true;
    }
    if(col>=9){
    	return sudoku_solver(row+1,0);
    }
    if(sudoku[row][col] == 0){
    	vector<int> options = alloptions(row,col);
        if(options.size()==0){
            //backtrack
            return false;
        }
        else{
            for(int k=0;k<options.size();k++){
                sudoku[row][col]=options[k];
                 bool x=true;
                if(col<9){
                    x=sudoku_solver(row, col+1);
                }
                else{
                    x=sudoku_solver(row+1,0);
                }
                if(x){
                    return x;
                }
            }
        sudoku[row][col]=0;
        return false;

        //     sudoku[i][j] = options.back();

        //               if(col < 9){

        //         if(sudoku_solver(row, col+1)){

        //             return true;

        //         }else{

        //             options.pop_back();

        //             if(options.size() != 0){

        //               sudoku[i][j] = options.back();

        //             }else{

        //                 sudoku[i][j] = 0;

        //                 return false;

        //             }

        //         }

        //     }else{

        //         if(sudoku_solver(row+1, col)){

        //             true;

        //         }else{

        //             options.pop_back();

        //             if(options.size() != 0){

        //               sudoku[i][j] = options.back();

        //             }else{

        //                 sudoku[i][j] = 0;

        //                 return false;

        //             }

        //         }

        //     }

        }
    }
    return sudoku_solver(row,col+1);
}

int main(){
    // write your code here
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
              cin>>sudoku[i][j];
        }
    }
     bool a = sudoku_solver(0,0);
    if(a){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
