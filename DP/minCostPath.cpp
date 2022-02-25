int minCostPath(int **input, int m, int n,int row,int col)
{
    if(row == m-1 && col == n-1){
        return input[row][col];
    }
	//Write your code here my approach
    //for right
//     int mini = INT_MAX;
//     if(col+1<n){
//      int option1 = minCostPath(input,m,n,row,col+1);
//      mini = min(mini,option1);
//     }
//     //For below
//     if(row+1<m){
//      int option2 = minCostPath(input,m,n,row+1,col);
//      mini = min(mini,option2);
//     }
    
//     //For dig
//     if(row+1<m && col+1<n){
//      int option3 = minCostPath(input,m,n,row+1,col+1);
//      mini = min(mini,option3);
        
//     }
    //If anyone exceed then returns +infinity any other will discard auto
    if(row>=m || col >=n){
        return INT_MAX;
    }
    //Right
     int option1 = minCostPath(input,m,n,row,col+1);
    //below
     int option2 = minCostPath(input,m,n,row+1,col);
    //Diagonal
     int option3 = minCostPath(input,m,n,row+1,col+1);
    
     return min(option1,min(option2,option3))+input[row][col];

    
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here
    return minCostPath(input,m,n,0,0);
}
