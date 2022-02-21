//----x-----x--- it means between x and x is 0

#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    int sum =0;
    int maxL = 0;
    unordered_map<int,int> um;
    for(int i =0; i<n;i++){
        sum+=arr[i];
        if(sum == 0){
            int len = i+1;
            if(len > maxL) maxL = len;
        }else{
            
        
        if(um.find(sum)!=um.end()){
            int len = i-um[sum];
            if(len > maxL) maxL = len;
        }else{
            um[sum] = i;
        }
        }
    }
    return maxL;
}
