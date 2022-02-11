#include<unordered_map>

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> freq;
   
    
    for(int i = 0; i<n; i++){
        freq[arr1[i]]++;
    }
    
    for(int i =0; i<m;i++){
         if(freq.count(arr2[i])>0){
          cout<<arr2[i]<<endl;
          if(freq[arr2[i]]>1){
              freq[arr2[i]]--;
          }else{
              freq.erase(arr2[i]);
          }   
          
        }
    }
    
}
