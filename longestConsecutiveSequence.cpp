#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    if(n == 0){
        return {0};
    }
    unordered_map<int,pair<bool,int>> seen;
    for(int i =0; i<n;i++){
        pair<bool,int> p;
        p.first = true;
        p.second = i;
        seen[arr[i]]=p;
    }
    int start=-1;
    int maxL=0;
    for(int i =0;i<n;i++){
        if(seen[arr[i]].first){
            int track = arr[i]+1;
            int len=1;
            seen[arr[i]].first = false;
            while(seen.find(track)!=seen.end()){
                len++;
                seen[track].first = false;
                track++;
               
            }
             track = arr[i]-1;
             while(seen.find(track)!=seen.end()){
                len++;
                seen[track].first = false;
                track--;  
            }
          
                if(len == maxL){
                    if(seen[track+1].second < seen[start].second){
                    maxL = len;
                    start = track+1;
                    }
                }else{
                     if(len> maxL){
                maxL = len;
                start = track+1;
                }
                }
          
        }
    }
    return {start,start+maxL-1};
    
}
