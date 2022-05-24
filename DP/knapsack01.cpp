#include<vector>
//t.c = O(2^N)
int brute(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    //base
    if(n == 0 || maxWeight == 0){
        return 0;
    }
    //if the weight is greater than max weight
    int a = 0;
    if(weights[0]<=maxWeight){
        a = knapsack(weights+1,values+1,n-1,maxWeight-weights[0])+values[0];
    }
    int b = knapsack(weights+1,values+1,n-1,maxWeight);
    return max(a,b);
    
    
    if(maxWeight == 0 || n ==0) return 0; //first include the weight int a =0; if(maxWeight>=weights[0]) a = values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]); //dont include int b = knapsack(weights+1,values+1,n-1,maxWeight); return max(a,b);
    
}
//O(n*W) space = O(n*W)
int byDP(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    //base
    vector<vector<int>> v(n+1,vector<int>(maxWeight+1,-1));
    for(int i =0;i<=maxWeight;i++){
        v[0][i] = 0;
    }
    for(int i =0;i<=n;i++){
        v[i][0] = 0;
    }
    for(int i =1; i<=n;i++){
        for(int j =1; j<=maxWeight;j++){
            if(j-weights[i-1]>=0){
                v[i][j] = max(v[i-1][j],values[i-1]+v[i-1][j-weights[i-1]]);
            }
            else{
                v[i][j] = v[i-1][j];
            }
        }
    }
    //if the weight is greater than max weight
    return v[n][maxWeight];
}
}
//O(n*W) space = O(n*W)
int memo(int *weights, int *values, int n, int maxWeight,vector<vector<int>> &v)
{
	//write your code here
    //base
    if(n == 0 || maxWeight == 0){
        return 0;
    }
    //if the weight is greater than max weight
    if(v[n][maxWeight]!=-1){
        return v[n][maxWeight];
    }
    int a = 0;
    if(weights[0]<=maxWeight){
        a = memo(weights+1,values+1,n-1,maxWeight-weights[0],v)+values[0];
    }
    int b = memo(weights+1,values+1,n-1,maxWeight,v);
    v[n][maxWeight] = max(a,b);
    return max(a,b);
}



int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    // vector<vector<int>> v(n+1,vector<int>(maxWeight+1,-1));
    
    // return memo(weight,value,n,maxWeight,v);
    return byDP(weight,value,n,maxWeight);
    
}
