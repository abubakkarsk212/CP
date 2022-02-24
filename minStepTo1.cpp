int byIterative(int n){
	//Write your code here
    int arr[n+1];
    arr[1] = 0;
    for(int i =2; i<=n;i++){
        int mini = arr[i-1];
        if(i%2 == 0){
            int b = arr[i/2];
            mini = min(mini,b);
        }
        if(i%3==0){
            int c = arr[i/3];
            mini = min(mini,c);
        }
        arr[i] = mini+1;
    }
    return arr[n];
}
int byMemo(int n,int *arr){
    if(n<=1) return 0;
	//Write your code here
     int a;
    if(arr[n]!=-1){
       return arr[n];
    }
    
    int mini =byMemo(n-1,arr);;
     if(n%2 == 0){
        int b = byMemo(n/2,arr);
        mini = min(mini,b);
    }
    if(n%3 == 0){
        int c = byMemo(n/3,arr);
        mini = min(mini,c);
    }
    arr[n] = mini+1;
    return arr[n];
}
int brute(int n){
    if(n==1) return 0;
	//Write your code here
    int a = brute(n-1);
    int mini =a;
    if(n%2 == 0){
        int b = brute(n/2);
        mini = min(mini,b);
    }
    if(n%3 == 0){
        int c = brute(n/3);
        mini = min(mini,c);
    }
    return mini+1;
}
int countMinStepsToOne(int n)
{
    //by memo
    int *arr = new int[n+1];
    for(int i =0; i<=n;i++){
        arr[i]=-1;
    }
    // return byMemo(n,arr)-1;
    
    //By iteratively
    return byIterative(n);
}
