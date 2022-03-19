class Solution {
public:
    //By o(n), kind of dp
    vector<int> approach2(int n){
        vector<int> v(n+1);
        v[0] = 0;
        for(int i =1; i<=n;i++){
        //if even means x/2 = y -> for even LSB is always 0 so no of set bits in x = no of set bits             //in y
            if(i%2 == 0){
                int ind = i/2;
                v[i] = v[ind];
            }
            //if odd means x/2 = y -> for odd LSB is always 1 so /2 means right shift so 1 will be lost             //so no of set bits in x = no of set bits in y +1             
            else{
               int ind = i/2;
                 v[i] = v[ind]+1;
            }
        }
        return v;
    }
    
    //O(nlogn)
    vector<int> approach1(int n) {
        
       vector<int> ans;
        for(int i =0; i<=n;i++){
            int num =i;
            int count =0;
            while(num!=0){
                if(num%2!=0) count++;
                num/=2;
            }
            ans.push_back(count);
        }
        return ans;
    }
    vector<int> countBits(int n) {
       
        return approach2(n);   
    }
};
