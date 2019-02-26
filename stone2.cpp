#include<iostream>
#include<algorithm>
using namespace std;
int* a;
int* w;
const int INF=1e9;
int** result;
int solve(int i,int j)
{
    if(i==j){
        return 0;
    }
    if(j-i==1){
        return a[i]+a[j];
    }
    if(result[i][j]>=0){
        return result[i][j];
    }
    int ans=INF;
    for(int k=i;k<j;k++){
        ans=min(ans,solve(i,k)+solve(k+1,j)+w[j]-(i-1<0?0:w[i-1]));
    }
    result[i][j]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    a=new int[n];
    w=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    w[0]=a[0];
    for(int i=1;i<n;i++){
        w[i]=w[i-1]+a[i];
    }
    result=new int*[n];
    for(int i=0;i<n;i++){
        result[i]=new int[n];
        for(int j=0;j<n;j++){
            result[i][j]=-1;
        }
    }
    cout<<solve(0,n-1)<<endl;
    return 0;
}