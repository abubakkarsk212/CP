class Solution {
public:
    bool isSafe(vector<string> board,int n,int r,int c){
        //check colwise
        int dupCol = c;
        int dupRow = r;
        //horizontal
        while(dupCol>=0){
            if(board[dupRow][dupCol] == 'Q') return false;
            dupCol--;
        }
        dupCol = c;
        dupRow = r;
        while(dupCol>=0 && dupRow>=0){
            if(board[dupRow][dupCol] == 'Q') return false;
            dupCol--;
            dupRow--;
            
        }
        dupCol = c;
        dupRow = r;
        while(dupCol>=0 && dupRow<n){
            if(board[dupRow][dupCol] == 'Q') return false;
            dupCol--;
            dupRow++;
            
        }
        
        return true;
    }
    //T.c(N*N!) and space = O(N^2)
    void helper(int n,vector<vector<string>> &ans,vector<string> &board,int col) {
       if(col == n){
          ans.push_back(board);
           return;
       }
       
       for(int i = 0; i<n;i++){
           if(isSafe(board,n,i,col)){
               board[i][col] ='Q';
               helper(n,ans,board,col+1);
               board[i][col] ='.';
           }
       } 
    }
    void helper1(int n,vector<vector<string>> &ans,vector<string> &board,int col,vector<int> &leftArr,vector<int> &digUp,vector<int> &digDown) {
       if(col == n){
          ans.push_back(board);
           return;
       }
       
       for(int i = 0; i<n;i++){
           if(leftArr[i] == 0 && digUp[n-1 + col-i] == 0 && digDown[i+col] == 0 ){
               board[i][col] ='Q';
               leftArr[col] = 1;
               digUp[n-1 + col-i] = 1;
               digDown[i+col] = 1;
               helper1(n,ans,board,col+1,leftArr,digUp,digDown);
               board[i][col] ='.';
               leftArr[col] = 0;
               digUp[n-1 + col-i] = 0;
               digDown[i+col] = 0;
           }
       } 
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n); 
       string s(n,'.');
       for(int i =0; i<n;i++){
           board[i] = s;
       } 
        //solving column wise
       // helper(n,ans,board,0); 
       // return ans; 
        
       vector<int> leftArr(n,0); 
       vector<int> digUp(2*n-1,0);
       vector<int> digDown(2*n-1,0); 
       helper1(n,ans,board,0,leftArr,digUp,digDown); 
       return ans; 
    }
};
