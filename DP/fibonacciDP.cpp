#include<iostream>
using namespace std

//By iteratively O(n) also called DP(Bottom Up, best approach)
int fibo_3(int n){
int arr[n+1];
arr[0] = 0;
arr[1] = 1;
for(int i =2; i<n; i++){
arr[i] = arr[i-1]+arr[i-2];
}
return arr[n];

}


//By recursionO(2^n)
int fib(int n){
if(n<=1){
return n;
}
return fib(n-1)+fib(n-2);
}

//By DP O(n)
int fibo_helper(int n,int *arr){
if(n<=1){
return n;
}
//First check if it is exist in array
if(arr[n]!=-1){
return arr[n];
}
//It means not exist so calculate and save for future use
int a = fibo_helper(n-1,arr);
int b = fibo_helper(n-2,arr);
arr[n] = a+b;
return arr[n];
}




int fibo_2(int n){
int *arr = new int[n+1];
//as it is garbage so initialize, it will problem to check is value exist
return fibo_helper(int n,arr);


}
