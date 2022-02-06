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
    for(int i =1; i<n;i++){
     bool res = insert(arr,i);  
        if(!res){
            return false;
        }
    }
    return true;
}
