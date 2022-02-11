#include<unordered_map>
#include<climits>
//O(n)
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> freqMap;
    for(int i =0; i<n;i++){
        freqMap[arr[i]]++;
    }
    int max =INT_MIN ,ind = 0;
    for(int i = 0; i< n;i++){
        if(freqMap[arr[i]]>max){
            max = freqMap[arr[i]];
            ind = arr[i];
        }
    }
    return ind;
}
