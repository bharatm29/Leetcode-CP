#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

bool isValid(vector<vector<string>> v){
    map<int, set<string>> rows;
    map<int, set<string>> cols;
    map<pair<int, int>, set<string>> squares;
    
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(v[r][c] == "."){
                
                continue;
            }           
            if(rows[r].count(v[r][c]) || cols[c].count(v[r][c]) || 
                    squares[{r/3, c/3}].count(v[r][c])
              ){
                return false;
            }
            rows[r].insert(v[r][c]);
            cols[c].insert(v[r][c]);
            squares[{r/3, c/3}].insert(v[r][c]);
        }
    }

    return true;
    
}

int main(){
    
    vector<vector<string>> v = 
    {{"5","3",".",".","7",".",".",".","."}
        ,{"6",".",".","1","9","5",".",".","."}
        ,{".","9","8",".",".",".",".","6","."},
            {"8",".",".",".","6",".",".",".","3"}
        ,{"4",".",".","8",".","3",".",".","1"}
        ,{"7",".",".",".","2",".",".",".","6"}
        ,{".","6",".",".",".",".","2","8","."}
        ,{".",".",".","4","1","9",".",".","5"}
        ,{".",".",".",".","8",".",".","7","9"}};

    bool flag = isValid(v);
    if(flag){
        
        cout<<"YES"<<endl;
    }
    else{
        
        cout<<"NOPE"<<endl;
    }
    return 0;
}
