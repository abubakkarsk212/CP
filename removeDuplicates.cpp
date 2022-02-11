#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//O(n^2)
vector<int> removeDuplicateBrute(int *a, int size){
    vector<int> unique;
    bool isseen = false;
    for(int i =0; i<size; i++){
        for(int j =0; j<unique.size();j++){
            if(unique[j] == a[i]){
                isseen = true;
                break;
            }
        }
        if(!isseen)
         unique.push_back(a[i]); 
        else
          isseen = false;
    }
    return unique;
}
//O(n)
vector<int> removeDuplicate(int *a, int size){
    vector<int> unique;
    unordered_map<int,bool> seen;
    for(int i =0; i<size; i++){
       if(seen.count(a[i])>0){
           continue;
       }
       seen[a[i]] = true;
       unique.push_back(a[i]);
    }
    return unique;
}
int main()
{
    int arr[] = {1,2,3,2,3,4,5,2,3};
    vector<int> res = removeDuplicateBrute(arr,9);
    for(int i =0; i<res.size();i++){
        cout<<res[i]<<" ";
    }
    

    return 0;
}
