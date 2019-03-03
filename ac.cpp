#include<iostream>
#include<string>
using namespace std;
const int N=1e5;
const int Z=26;
int tree[N][Z];
int nex[N];
int queue[N];
int cache[N];
int total=1;
inline void insert(string s){
    int len=s.size();
    int node=1;
    for(int i=0;i<len;i++){
        int c=s[i]-'a';
        if(!tree[node][c]){
            tree[node][c]=++total;
        }
        node=tree[node][c];
    }
    cache[node]++;
}
inline void bfsBuild(){
    nex[1]=0;
    queue[0]=1;
    for(int h=0,r=0;h<=r;h++){
        int node=queue[h];
        for(int i=0;i<Z;i++){
            if(!tree[node][i]){
                tree[node][i]=tree[nex[node]][i];
            }else{
                int k=nex[node];
                while(k>1&&!tree[k][i]){
                    k=nex[k];
                }
                nex[tree[node][i]]=tree[k][i];
                queue[++r]=tree[node][i];
            }
        }
    }
}
inline void find(string msg,int& ans){
    int node=1;
    int len=msg.size();
    for(int i=0;i<len;i++){
        int c=msg[i]-'a';
        int k=tree[node][c];
        while(k>1){
            ans+=cache[k];
            cache[k]=0;
            k=nex[k];
        }
        node=tree[node][c];
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<Z;i++){
        tree[0][i]=1;
    }
    for(int i=0;i<n;i++){
        cin>>s;
        insert(s);    
    }
    bfsBuild();
    int ans=0;
    cin>>s;
    find(s,ans);
    cout<<ans<<endl;
    return 0;
}