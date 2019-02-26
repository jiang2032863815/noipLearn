#include<iostream>
#include<algorithm>
using namespace std;
int* w;
int* v;
int** result;
int dfs(int i,int m)
{
    if(i<0){
        return 0;
    }
    if(result[i][m]>=0){
        return result[i][m];
    }
    if(w[i]>m){
        result[i][m]=dfs(i-1,m);
        return result[i][m];
    }
    result[i][m]=max(dfs(i-1,m),dfs(i-1,m-w[i])+v[i]);
    return result[i][m];
}
int main()
{
    int n,m;
    cin>>n>>m;
    w=new int[n];
    v=new int[n];
    result=new int*[n];
    for(int i=0;i<n;i++){
        result[i]=new int[m+1];
        for(int j=0;j<=m;j++){
            result[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<dfs(n-1,m)<<endl;
    return 0;
}