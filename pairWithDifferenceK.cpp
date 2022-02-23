#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    int count =0;
    unordered_map<int,int> map;
    map[arr[0]] = 1;
    for(int i =1; i<n;i++){
        if(map.find(arr[i]+k)!=map.end()){
            count+=map[arr[i]+k];
            
        }
        if(k!=0){
           if(map.find(arr[i]-k)!=map.end()){
            count+=map[arr[i]-k];  
               
        } 
        }
        map[arr[i]]++;
    }
    return count;
}
