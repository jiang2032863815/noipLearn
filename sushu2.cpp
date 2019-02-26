#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=20;
int n,num[MAXN];
bool t[MAXN],prime[MAXN*2];
void build(int k){
    if(k==n){
        if(prime[num[0]+num[n-1]]){
            for(int i=0;i<n;i++){
                cout<<num[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=2;i<=n;i++){
        if(!t[i]&&prime[i+num[n-1]]){
            num[k]=i;
            t[i]=true;
            build(k+1);
            t[i]=false;
        }
    }
}
int main()
{
    cin>>n;
    memset(t,false,sizeof(t));
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i<n*2;i++){
        if(prime[i]){
            for(int j=2;j*i<n*2;j++){
                prime[i*j]=false;
            }
        }
    }
    num[0]=1;
    t[1]=true;
    build(1);
    return 0;
}