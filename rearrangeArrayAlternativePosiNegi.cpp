#include <iostream>

using namespace std;
void rotateRight(int arr[],int f,int t){
    int temp = arr[t];
    for(int j = t-1 ;j>=f;j--){
        arr[j+1] = arr[j];
    }
    arr[f] = temp;
}
void rearrangeAlternative(int arr[],int n){
    int wrongIndex =-1; 
    for(int i =0; i<n;i++){
        if(wrongIndex!=-1){
            if(arr[wrongIndex]>0 && arr[i]<0 || arr[wrongIndex]<0 && arr[i]>0){
                rotateRight(arr,wrongIndex,i);
                if(i-wrongIndex>=2){
                    wrongIndex +=2;
                }else{
                    wrongIndex = -1;
                }
            }
        }else{
            if(i%2==0 &&arr[i]>0 || i%2!=0 && arr[i]<0){
                wrongIndex = i;
            }
        }
    }
}

int main()
{
    int arr[] = {-1,1,2,3,-3,-2};
    rearrangeAlternative(arr,6);
    for(int i =0; i<6;i++){
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}
