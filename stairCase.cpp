long  memoization(int n,long *arr){
      if(n==0){
        return 1;
    }
    if(arr[n]!=-1) return arr[n];
    long  a = memoization(n-1,arr);
    long  b=0,c=0;
    if(n-2>=0){
        b=memoization(n-2,arr);
    }
    if(n-3>=0){
        c=memoization(n-3,arr);
    }
    arr[n] = a+b+c;
    return arr[n];
}
//By DP
long byIterative(int n){
    long *arr = new long[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i =2; i<=n;i++){
       long a = arr[i-1];
       long b =0,c =0; 
        if(i-2>=0){
            b = arr[i-2];
        }
        if(i-3>=0){
            c = arr[i-3];
        }
        arr[i] = a+b+c;
    }
    return arr[n];
}
long staircase(int n)
{
	//Write your code here
   // long  *arr = new long[n+1];
   //  for(int i =0; i<=n;i++){
   //      arr[i] = -1;
   //  }
    return byIterative(n);
}
