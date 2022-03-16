//by dp
int maxMoneyLootedDP(int *arr, int n)
{
    if(n<=0) return 0;
	//Write your code here
    int outarray[n+1];
    outarray[0] = 0;
    outarray[1] = arr[0];
     for(int i =2;i<=n;i++){
          int a = arr[i-1]+outarray[i-2];
          int b = outarray[i-1];
          outarray[i] = max(a,b);
     }
   
  
    return outarray[n];
    
}

//by memoization
int maxMoneyLootedMemo(int *arr, int n,int *outarray)
{
    if(n <=0) return 0;
    if(n == 1) return arr[0];
    if(outarray[n]!=-1) return outarray[n]; 
    int a = arr[n-1]+maxMoneyLootedMemo(arr,n-2,outarray);
    int b = maxMoneyLootedMemo(arr,n-1,outarray);
    outarray[n] = max(a,b);
    return outarray[n];
    
    
}
//by brute
int maxMoneyLootedBrute(int *arr, int n)
{
	// if(n<=0) return 0;
	// //Write your code here
	// int a = arr[0]+maxMoneyLootedBrute(arr+2,n-2);
	// int b = 0;
	// if(n>1)
	// b = arr[1]+maxMoneyLootedBrute(arr+3,n-3);
	// return max(a,b);
    
    // 
    if(n <=0) return 0;
    if(n == 1) return arr[0];
    int a = arr[n-1]+maxMoneyLootedBrute(arr,n-2);
    int b = maxMoneyLootedBrute(arr,n-1);
    return max(a,b);
    
    
}
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    // int *outA = new int[n+1];
    // for(int i =0; i<=n;i++){
    //     outA[i] = -1;
    // }
    return maxMoneyLootedDP(arr,n);
}
