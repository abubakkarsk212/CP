#include<unordered_map>

//t.c O(N) and sc(N)
int approach2(int *arr, int n){
    unordered_map<int,int> s;
    int count = 0;
    s[arr[0]] = 1;
    for(int i =1; i<n;i++){
        if(s.count(-1 *arr[i])>0){
            int freq = s[-1 *arr[i]];
            count+=freq;
        }
        s[arr[i]]++;
    }
    return count;
}
int pairSum(int *arr, int n) {
	// Write your code here
    return approach2(arr,n);
}
