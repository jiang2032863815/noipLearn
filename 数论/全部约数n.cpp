#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<1<<" ";
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}