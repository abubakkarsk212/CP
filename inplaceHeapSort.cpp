
      
        int parent = 0;
        int temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
       
        int minI = parent;
        int lChild = 2*parent +1;
        int rChild = 2*parent +2;
        while(lChild <j){
        if(arr[lChild] <arr[parent]){
            minI = lChild;
        }
         if(rChild <j)   
          if(arr[minI] > arr[rChild]) minI = rChild;
        
        if(parent == minI){
            break;
        }
        int temp = arr[parent];
        arr[parent] = arr[minI];
        arr[minI] = temp;
        parent = minI;
        lChild = 2*parent +1;
        rChild = 2*parent +2;
        }
}
void insert(int pq[],int j) {
    // Write your code
        int childIndex = j;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
}
void heapSort(int arr[], int n) {
    // Write your code
    //first build min heap
    for(int i =1; i<n;i++){
       insert(arr,i); 
    }
    for(int j = n-1; j>0; j--){
        removeMin(arr,j);
    }
}
