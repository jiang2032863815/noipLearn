#include<bits/stdc++.h>
using namespace std;
int f[20100][20100],sum[20100],n;
 
int main(){
    memset(f,10000,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum[i]+=sum[i-1]+x;
        f[i][i]=0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<=j-1;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}