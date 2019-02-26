#include <iostream>
#include <queue>
using namespace std;
struct P
{
    int x, y, dir, step;
};
const int MAXN = 110;
const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int map[MAXN][MAXN];
bool vis[MAXN][MAXN][4];
int main()
{
    int n, m, startx, starty, endx, endy;
    queue<P> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> startx >> starty >> endx >> endy;
    startx--, starty--, endx--, endy--;
    for (int i = 0; i < 4; i++)
    {
        vis[startx][starty][i] = true;
    }
    P start;
    start.dir = 100;
    start.step = -1;
    start.x = startx;
    start.y = starty;
    q.push(start);
    while (!q.empty())
    {
        P h = q.front();
        if (h.x == endx && h.y == endy)
        {
            cout << h.step << endl;
            break;
        }
        int ox, oy;
        for (int i = 0; i < 4; i++)
        {
            if(i==h.dir||i-h.dir==2||h.dir-i==2){
                continue;
            }
            ox=h.x+d[i][0],oy=h.y+d[i][1];
            while(ox>=0&&oy>=0&&ox<n&&oy<m&&!map[ox][oy]&&!vis[ox][oy][i]){
                P temp;
                temp.dir=i;
                temp.x=ox;
                temp.y=oy;
                temp.step=h.step+1;
                vis[ox][oy][i]=true;
                ox+=d[i][0],oy+=d[i][1];
                q.push(temp);
            }
        }
        q.pop();
    }
    return 0;
}