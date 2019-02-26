#include<iostream>
#include<algorithm>
using namespace std;
int* a;
int* b;
int** result;
int dfs(int i,int j)
{
    if(i==-1||j==-1){
        return 0;
    }
    if(a[i]==b[j]){
        if(result[i][j]>=0){
            return result[i][j];
        }
        result[i][j]=dfs(i-1,j-1)+1;
        return result[i][j];
    }
    if(result[i][j]>=0){
        return result[i][j];
    }
    result[i][j]=max(dfs(i,j-1),dfs(i-1,j));
    return result[i][j];
}
int main()
{
    int m,n;
    cin>>m>>n;
    a=new int[m];
    b=new int[n];
    result=new int*[m];
    for(int t=0;t<m;t++){
        result[t]=new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            result[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        cin>>b[j];
    }
    cout<<dfs(m-1,n-1)<<endl;
    return 0;
}