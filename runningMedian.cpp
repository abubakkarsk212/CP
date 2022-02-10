#include<vector>
#include <bits/stdc++.h>
//T.c = nlogn. and space o(n)
void usingMinMaxHeap(int *arr, int n){
    if(n == 0) return;
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
    
    int i =0;
    maxH.push(arr[i]);
    int size1 = maxH.size();
    int size2 = minH.size();
    cout<<arr[i]<<" ";
    i++;
    while(size1+size2!=n){
       
               if(arr[i]<maxH.top()){
                   maxH.push(arr[i]);
                   i++;
                   size1++;
               }else{
                   minH.push(arr[i]);
                   i++;
                   size2++;  
               }
                if(abs(size1-size2)<=1){
                    if(size1 == size2){
                         cout<< (maxH.top() + minH.top())/2<<" ";
                    }else{
                        if(size1 < size2){
                            cout<< minH.top()<<" ";
                        }else{
                            cout<< maxH.top()<<" "; 
                        }
                    }
                }else{
                    if(size1 > size2){
                        int top = maxH.top();
                    maxH.pop();
                    size1--;
                    minH.push(top);
                    size2++;
                    if(size1 == size2){
                         cout<< (maxH.top() + minH.top())/2<<" ";
                    }else{
                       
                            cout<< maxH.top()<<" "; 
                    }
                    }
                    else{
                    int top = minH.top();
                    minH.pop();
                    size2--;
                    maxH.push(top);
                    size1++;
                   if(size1 == size2){
                         cout<< (maxH.top() + minH.top())/2<<" ";
                    }else{
                       
                            cout<< minH.top()<<" "; 
                    }
                    }
                   
                }
            }
      
}
void bruteForce(int *arr, int n){
    vector<int> list;
    for(int i = 0; i<n;i++){
        list.push_back(arr[i]);
        sort(list.begin(),list.end());
        int mid = list.size()/2;
        if(list.size()%2 == 0){ //for even
            int k = mid-1;
            cout << (list[mid] + list[k])/2<< " ";
        }else{
            cout<<list[mid]<<" ";
        }
    }
}
void findMedian(int *arr, int n)
{
    // Write your code here
    // bruteForce(arr,n);
    usingMinMaxHeap(arr,n);
}
