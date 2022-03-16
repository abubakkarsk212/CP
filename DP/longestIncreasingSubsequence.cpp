int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    //It is different type of dp problem here we have not thought about recursion here we need
    //previous value thats why we use dp
    int op[n];
    op[0] = 1;
    for(int i =1; i<n;i++){
        op[i] = 1;
        for(int j =i-1;j>=0;j--){
            if(arr[j]>=arr[i]){
                continue;
            }
            int possibleAns = op[j]+1;
            if(possibleAns>op[i]){
                op[i] = possibleAns;
            }
        }
    }
    int best =op[0];
    for(int i =1; i<n;i++){
        if(op[i]>best) best = op[i];
    }
    return best;
}
