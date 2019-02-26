#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool* is=new bool[n];
    for(int i=2;i<n;i++){
        is[i]=true;
    }
    for(int i=2;i*i<n;i++){
        if(!is[i]){
            continue;
        }
        for(int j=i*i;j<n;j+=i){
            is[j]=false;
        }
    }
    for(int i=2;i<n;i++){
        if(is[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}