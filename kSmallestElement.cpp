#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> ans;
    // if(k == 0){
    //     for(int i =0; i<n; i++){
    //         ans.push_back(arr[i]);
    //     }
    //     return ans;
    // }
    // if(n == 0) return NULL;
    priority_queue<int> pq;
    for(int i =0; i<k;i++){
        pq.push(arr[i]);
    }
    for(int i =k; i<n;i++){
       
            if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
    }
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
     reverse(ans.begin(), ans.end());
    return ans;
}
