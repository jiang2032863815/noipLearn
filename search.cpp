#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct road{
    int pos;
    int w;
};
struct dir{
    vector<road> points;
    int size;  
};
int n,x;
dir* mat;
bool** vis;
int* dis;
/*
无环
*/
void dfs(int pos,int now,int& ans){
    if(pos<0||pos>=n){
        return;
    }
    if(dis[pos]>now){
        return;
    }
    for(int i=0;i<mat[pos].size;i++){
        if(!vis[pos][mat[pos].points[i].pos]){
            vis[mat[pos].points[i].pos][pos]=true;
            dis[mat[pos].points[i].pos]=max(dis[mat[pos].points[i].pos],now+mat[pos].points[i].w);
            dfs(mat[pos].points[i].pos,now+mat[pos].points[i].w,ans);
        }
    }
    ans=max(ans,now);
}
int main(){
    cin>>n>>x;
    x--;
    mat=new dir[n];
    vis=new bool*[n];
    dis=new int[n]{0};
    for(int i=0;i<n;i++){
        vis[i]=new bool[n]{false};
        mat[i].size=0;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int pos1,pos2,w;
        cin>>pos1>>pos2>>w;
        pos1--,pos2--;
        road r1;
        r1.w=w;
        r1.pos=pos2;
        mat[pos1].points.push_back(r1);
        mat[pos1].size++;
        road r2;
        r2.w=w;
        r2.pos=pos1;
        mat[pos2].points.push_back(r2);
        mat[pos2].size++;
    }
    int ans=0;
    dfs(x,0,ans);
    cout<<ans<<endl;
    return 0;
}