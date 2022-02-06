//O(nlogn)
bool insert(int arr[], int j){
    int child = j;
    while(child>0){
    int parent = (child-1)/2;
    if(arr[child] > arr[parent]){
        return false;
    }
    child = parent;
    }
    return true;
}
bool isMaxHeap(int arr[], int n) {
    // Write your code here
//     for(int i =1; i<n;i++){
//      bool res = insert(arr,i);  
//         if(!res){
//             return false;
//         }
//     }
//     return true;
      //traversing each nodes and check its left and right child
    //It takes O(n)
    for(int i = 0;i<n;i++){
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<n){
            if(arr[left] >arr[i]){
                return false;
            }
        }
     if(right<n){
            if(arr[right] >arr[i]){
                return false;
            }
        }   
    }
    return true;
}
