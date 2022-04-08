#include<queue>


class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        //We should build the min heap inside constructor as we are callling only one time but if we //create inside add then will case TLE as it will be called for 10^4 times
        
        //2nd catch: follow this pattern to avoid Runtime error
        size = k;
       for(int i =0; i<nums.size();i++){
           pq.push(nums[i]);
           if(pq.size()>k){
               pq.pop();
           }
       }
        
     
    }
    
    int add(int val) {
       pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int kthLargest(int* arr, int n, int k) {
    // Write your code here
    //concept is maintain a min heap
    if(k>n){
        return -1;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0; i<k;i++){
        pq.push(arr[i]);
    }
    for(int i = k; i<n;i++){
        if(pq.top()<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
        
    }
    return pq.top();
}
