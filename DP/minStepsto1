#include <cmath>
//By DP O(n)
int byDP(int n) {
    // Write your code here
    long long arr[n+1];
    arr[0] = 1;
    arr[1] = 1;
    int mod = (int)pow(10,9)+7;
    
    for(int i =2;i<=n;i++){
    long long temp1 = ((long long)arr[i-1] * arr[i-1])%mod;
    long long temp2 = (2*(long long)(arr[i-1]) * arr[i-2])%mod;
    arr[i] = (temp1+temp2)%mod;
    }
    
    return arr[n];
    
}
//O(n)
int byMemoization(int n,long long *arr) {
    // Write your code here
    if(n<=1) return 1;
    if(arr[n]!=-1) return arr[n];
    int x = byMemoization(n-1,arr);
    int y = byMemoization(n-2,arr);
    int mod = (int)pow(10,9)+7;
    long long temp1 = ((long long)x * x)%mod;
    long long temp2 = (2*(long long)(x) * y)%mod;
    arr[n] = (temp1+temp2)%mod;
    return arr[n];
    
}
//O(2^n)
int byRec(int n){
    if(n<=1) return 1;
   
    int x = byRec(n-1);
    int y = byRec(n-2);
    int mod = (int)pow(10,9)+7;
    long long temp1 = ((long long)x * x)%mod;
    long long temp2 = (2*(long long)(x) * y)%mod;
    int ans = (temp1+temp2)%mod;
    return ans;
}
int balancedBTs(int n) {
    // Write your code here
    // long long *arr = new long long[n+1];
    // for(int i =0; i<=n;i++){
    //     arr[i] = -1;
    // }
    // return byMemoization(n,arr);
    return byRec(n);
}
