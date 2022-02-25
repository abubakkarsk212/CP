
int byMemo(int n,int *arr){
     if(n<=1) return n;
     if(arr[n]!=-1){
         return arr[n];
     }
    int mini = INT_MAX;
    for(int i =1;i*i<=n;i++){
        
            int steps = byMemo(n-i*i,arr)+1;
            mini = min(mini,steps);
    }
    arr[n] = mini;
    return arr[n];
}
int byRec(int n){
     if(n<=1) return n;
    int mini = INT_MAX;
    for(int i =1;i*i<=n;i++){
        if(i * i <=n){
            int steps = byRec(n-i*i)+1;
            mini = min(mini,steps);
        }else{
            return mini;
        }
    }
    return mini;
}
int minCount(int n)
{
	//Write your code here
   int *arr = new int[n+1];
    for(int i =0; i<=n;i++){
        arr[i]=-1;
    }
    return byMemo(n,arr);
}
