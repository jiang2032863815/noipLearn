#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Pos{
    int i;
    int j;
};
int main(){
    int a[6][6]={
        {1,0,1,0,1,1},
        {0,0,1,1,1,0},
        {1,0,1,1,0,1},
        {1,1,1,0,0,1},
        {1,0,0,0,1,0},
        {1,1,1,0,1,1}
    };
    int d[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
    queue<Pos> q;
    Pos p;
    p.i=0;
    p.j=0;
    q.push(p);
    cout<<0<<" "<<0<<endl;
    int use[6][6];
    memset(use,0,sizeof(use));
    use[0][0]=1;
    int c=1;
    while(!q.empty()&&p.i!=5&&p.j!=5){
        q.pop();
        for(int i=0;i<4;i++){
            int oi=p.i+d[i][0];
            int oj=p.j+d[i][1];
            if(oi>=0&&oj>=0&&oi<=5&&oj<=5&&a[oi][oj]&&!use[oi][oj]){
                Pos ins;
                ins.i=oi;
                ins.j=oj;
                q.push(ins);
            }
        }
        p=q.front();
        c++;
        cout<<p.i<<" "<<p.j<<endl;
    }
    return 0;
}