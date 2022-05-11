#include<iostream>
using namespace std;

//By DP
int lcsDp(string s1,string s2,int m,int n){
//First initialize the array for m =0 n, m n =0, m=0 n =0
int **arr = new int*[m+1];
for(int col =0; col<=n;col++){
arr[0][col] = 0;
} 

for(int row =1; row<=m;row++){
arr[row][0] = 0;
}
 
//fill remaining either by row or column wise
for(int row = 1; row<=m;row++){
 for(int col = 1; col<=n;col++){
  if(s1[m-row] == s2[n-col]){
   arr[row][col] = 1+arr[row-1][col-1];
}	
else{
int a = arr[row-1][col];
int b = arr[row][col-1];
int c = arr[row-1][col-1];
arr[row][col] = max(a,max(b,c));
}

}

}

return arr[m][n];
}

//By memo T.C = (m *n) and space =O( m*n)
int lcsMemo(string s1,string s2,int m,int n, int **arr){
//Base case
if(m == 0 || n == 0){
return 0;
}
if(arr[m][n] !=-1){
return arr[m][n];
}
int ans;
if(s1[0] == s2[0]){
ans = 1+lcsMemo(s1.substr(1),s2.substr(1),m-1,n-1,arr);
}
else{
int a = lcsMemo(s1.substr(1),s2,m-1,n,arr);
int b = lcsMemo(s1,s2.substr(1),m,n-1,arr);
int c = lcsMemo(s1.substr(1),s2.substr(1),m-1,n-1,arr);
ans = max(a,max(b,c));
}
arr[m][n] = ans;
return max(a,max(b,c));
}

//Brute(O(3^n)
int lcs(string s1,string s2){
//Base case
if(s1.size() == 0 || s2.size() == 0){
return 0;
}
if(s1[0] == s2[0]){
return 1+lcs(s1.substr(1),s2.substr(1));
}

int a = lcs(s1.substr(1),s2);
int b = lcs(s1,s2.substr(1));
int c = lcs(s1.substr(1),s2.substr(1));

return max(a,max(b,c));
}

int main(){
string s1;
string s2;
cin>> s1;
cin>>s2;
//cout<<lcs(s1,s2)<<endl;

/*int ** arr = new int*[4];
for(int i =0; i<=3;i++){
arr[i]=new int[5];
for(int j =0; j<=4;j++){
arr[i][j] = -1;
}

}*/
cout<<lcsDp(s1,s2,3,4);
}
