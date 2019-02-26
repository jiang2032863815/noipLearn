#include <iostream>
#include <queue>
using namespace std;
const char kong = '#';
const char ying = '.';
const char sui = 'E';
const char start = 'X';
const char endPos = 'O';
struct Result
{
    int x, y, state,step;
};
//state 0 站立,1 w为2的横卧, 2 w为1的横卧
//d 0向上，1向下，2向左，3向右
Result change(int x, int y, int state, int d)
{
    switch (state)
    {
    case 0:
    {
        switch (d)
        {
        case 0:
        {
            Result r;
            r.x = x;
            r.y = y - 1;
            r.state = 2;
            return r;
        }
        break;
        case 1:
        {
            Result r;
            r.x=x;
            r.y=y+1;
            r.state=2;
            return r;
        }
        break;
        case 2:
        {
            Result r;
            r.x=x-2;
            r.y=y;
            r.state=1;
            return r;
        }
        break;
        case 3:
        {
            Result r;
            r.x=x+1;
            r.y=y;
            r.state=1;
            return r;
        }
        break;
        }
    }
    break;
    case 1:
    {
        switch(d){
            case 0:
            {
                Result r;
                r.x=x;
                r.y=y-1;
                r.state=1;
                return r;
            }
            break;
            case 1:
            {
                Result r;
                r.x=x;
                r.y=y+1;
                r.state=1;
                return r;
            }
            break;
            case 2:
            {
                Result r;
                r.x=x-1;
                r.y=y;
                r.state=0;
                return r;
            }
            break;
            case 3:
            {
                Result r;
                r.x=x+2;
                r.y=y;
                r.state=0;
                return r;
            }
            break;
        }
    }
    break;
    case 2:
    {
        switch(d){
            case 0:
            {
                Result r;
                r.x=x;
                r.y=y-1;
                r.state=0;
                return r;
            }
            break;
            case 1:
            {
                Result r;
                r.x=x;
                r.y=y+2;
                r.state=0;
                return r;
            }
            break;
            case 2:
            {
                Result r;
                r.x=x-1;
                r.y=y;
                r.state=2;
                return r;
            }
            break;
            case 3:
            {
                Result r;
                r.x=x+1;
                r.y=y;
                r.state=2;
                return r;
            }
            break;
        }
    }
    break;
    }
}
int main()
{
    int n, m;
    while (cin >> n >> m&&!(n==0&&m==0))
    {
        int sx, sy,ex,ey;
        char **map = new char *[n + 2];
        bool*** vis;
        vis=new bool**[n];
        for(int i=0;i<n+2;i++){
            vis[i]=new bool*[m+2];
            for(int j=0;j<m+2;j++){
                vis[i][j]=new bool[3];
                for(int k=0;k<3;k++){
                    vis[i][j][k]=false;
                }
            }
        }
        map[0] = new char[m + 2];
        for (int j = 0; j < m + 2; j++)
        {
            map[0][j] = kong;
        }
        for (int i = 1; i < n + 1; i++)
        {
            map[i] = new char[m + 2];
            map[i][0] = kong;
            cin >> (map[i] + 1);
            for (int j = 1; j < m + 1; j++)
            {
                if (map[i][j] == start)
                {
                    sx = i;
                    sy = j;
                }
                if(map[i][j] == endPos){
                    ex=i;
                    ey=j;
                }
            }
            map[i][m + 1] = kong;
        }
        map[n + 1] = new char[m + 2];
        for (int j = 0; j < m + 2; j++)
        {
            map[n + 1][j] = kong;
        }
        Result start;
        start.state=0;
        start.x=sx;
        start.y=sy;
        start.step=0;
        vis[sx][sy][0]=true;
        queue<Result> q;
        q.push(start);
        while(!q.empty()){
            Result h=q.front();
            if(h.state==0&&h.x==ex&&h.y==ey){
                cout<<h.step<<endl;
                q.pop();
                break;
            }
            for(int d=0;d<4;d++){
                Result temp=change(h.x,h.y,h.state,d);
                if(vis[temp.x][temp.y][temp.state]){
                    continue;
                }
                bool ok=true;
                switch(temp.state){
                    case 0:
                    {
                        if(temp.x>=0&&temp.x<n+2&&temp.y>=0&&temp.y<m+2){
                            if(map[temp.x][temp.y]!=ying){
                                ok=false;
                            }
                        }else{
                            ok=false;
                        }
                    }
                    break;
                    case 1:
                    {
                        if(temp.x>=0&&temp.x<n+1&&temp.y>=0&&temp.y<m+2){
                            if(map[temp.x][temp.y]==kong||map[temp.x+1][temp.y]==kong){
                                ok=false;
                            }
                        }else{
                            ok=false;
                        }
                    }
                    break;
                    case 2:
                    {
                        if(temp.x>=0&&temp.x<n+2&&temp.y>=0&&temp.y<m+1){
                            if(map[temp.x][temp.y]==kong||map[temp.x][temp.y+1]==kong){
                                ok=false;
                            }
                        }else{
                            ok=false;
                        }
                    }
                    break;
                }
                if(ok){
                    temp.step=h.step+1;
                    cout<<temp.state<<";"<<temp.x<<","<<temp.y<<endl;
                    q.push(temp);
                }
            }
            q.pop();
        }
        free(map);
    }
    return 0;
}