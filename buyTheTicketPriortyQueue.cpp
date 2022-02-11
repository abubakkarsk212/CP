#include<queue>
//T.c O(NlogN) sc O(N) N is no of people in queue
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    int t =0;
  priority_queue<int> pq;
  queue<int> ix;
  for(int i =0; i<n; i++){
      pq.push(arr[i]);
      ix.push(i);
  } 
   
    while(ix.front() != k || arr[ix.front()]!= pq.top()){
    int topPq = pq.top();
    if(arr[ix.front()]!= topPq){
        int topQ = ix.front();
        ix.pop();
        ix.push(topQ);
    }
	else{
        t++;
        pq.pop();
        ix.pop();
       
    }
        
    }
    return ++t;
}
