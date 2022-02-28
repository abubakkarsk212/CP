int byDP(int **input, int m, int n){
 
    int **arr = new int*[m];
    for(int i =0; i<m;i++){
        arr[i] = new int[n];
    }
    //Initialize last cell
    arr[m-1][n-1] = input[m-1][n-1];
    //Fill last row
    for(int i = n-2; i>=0;i--){
        arr[m-1][i] = arr[m-1][i+1]+input[m-1][i];
    }
    //fill last col
    for(int i = m-2; i>=0;i--){
        arr[i][n-1] = arr[i+1][n-1]+input[i][n-1];
    }
    //fill remaining row = m-2 and col = n-2
    for(int i = m-2; i>=0;i--){
        for(int j =n-2;j>=0;j--){
         int a = min(arr[i][j+1],min(arr[i+1][j],arr[i+1][j+1]))+input[i][j];
         arr[i][j] = a;   
            
        }
    }
    
   
    
    
     return arr[0][0];
}
int byMemo(int **input, int m, int n,int row,int col,int **storeArray){
 if(row == m-1 && col == n-1){
        return input[row][col];
    }
    
     if(row>=m || col >=n){
        return INT_MAX;
    }
    if(storeArray[row][col]!=-1){
        return storeArray[row][col];
    }
    //Right
     int option1 = byMemo(input,m,n,row,col+1,storeArray);
    //below
     int option2 = byMemo(input,m,n,row+1,col,storeArray);
    //Diagonal
     int option3 = byMemo(input,m,n,row+1,col+1,storeArray);
    
     int a = min(option1,min(option2,option3))+input[row][col];
     storeArray[row][col] = a;
     return a;
}

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
