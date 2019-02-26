/*
分解质因数法的推论
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=2;i*i<=n;i++){
        while(n>i){
            if(n%i==0){
                v.push_back(i);
                n/=i;
            }else{
                break;
            }
        }
    }
    v.push_back(n);
    int size=v.size();
    cout<<1<<" ";
    map<int,bool> m;
    for(int i=0;i<size;i++){
        if(!m[v[i]]){
            m[v[i]]=true;
            cout<<v[i]<<" ";
        }
        int k=v[i];
        for(int j=1;j<size-1;j++){
            k*=v[j];
            if(!m[k]){
                cout<<k<<" ";
                m[k]=true;
            }
        }
    }
    cout<<endl;
}