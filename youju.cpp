#include<iostream>
#include<algorithm>
using namespace std;
int* x;
int** dist;
const int INF=1e9;
int** result;
int solve(int i,int j)
{
    if(j<=0){
        return 0;
    }
    if(j==1){
        return dist[0][i];
    }
    if(result[i][j]>=0){
        return result[i][j];
    }
    int ans=INF;
    for(int k=i-1;k>=0;k--){
        ans=min(solve(k,j-1)+dist[k+1][i],ans);
    }
    return ans;
}
int main()
{
    int v,p;
    cin>>v>>p;
    x=new int[v];
    for(int i=0;i<v;i++){
        cin>>x[i];
    }
    dist=new int*[v];
    result=new int*[v];
    for(int i=0;i<v;i++){
        dist[i]=new int[v];
        result[i]=new int[p+1];
        for(int j=i;j<v;j++){
            int p=x[(i+j)/2];
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=abs(p-x[k]);
            }
            dist[i][j]=sum;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<=p;j++){
            result[i][j]=-1;
        }
    }
    cout<<solve(v-1,p)<<endl;
    return 0;
}