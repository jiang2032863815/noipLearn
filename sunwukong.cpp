#include<iostream>
#include<algorithm>
using namespace std;
int* a;
int* f;
const int MIN=-1e9;
int main()
{
    int n;
    cin>>n;
    a=new int[n+1];
    f=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=MIN;
    }
    f[1]=a[1];
    for(int i=1;i<=n;i++){
        f[i+1]=max(f[i+1],f[i]+a[i+1]);
        for(int j=2;j*i<n;j++){
            f[j*i]=max(f[j*i],f[i]+a[i*j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
}