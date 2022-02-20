#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    long b=0;
    cin>>n;
    long pv = 1;
    while(n){
        int rem = n%2;
        b = b + rem * pv;
        pv = pv * 10;
        n = n/2;
    }
    cout<<b;
}
