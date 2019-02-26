#include<iostream>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    int* w=new int[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int h=0;
    int r=n-1;
    int ans=0;
    while(h<r){
        if(w[h]+w[r]<=c){
            ans++;
            h++;
            r--;
        }else if(w[r]<=c){
            ans++;
            r--;
        }else if(w[h]<=c){
            ans++;
            h++;
        }
    }
    if(r==h){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}