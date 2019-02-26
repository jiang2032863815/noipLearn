#pragma GCC diagnostic error "-std=c++11"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const long long inf = 1e18;

int n,m,p[300100],f[300100][20],d[300100];
long long w[300100][20][2][2],up[300100][2],dp[300100][3];
vector<int> edge[300100];

void dfs(int now) {
  dp[now][1] = p[now];
  dp[now][0] = 0;
  for (auto it = edge[now].begin();it != edge[now].end();it++)
    if (*it != f[now][0]) {
      f[*it][0] = now;
      d[*it] = d[now] + 1;
      dfs(*it);
      dp[now][1] += dp[*it][2];
      dp[now][0] += dp[*it][1];
    }
  dp[now][2] = min(dp[now][0],dp[now][1]);
}

void calc_up(int now) {
  if (now > 1) {
    up[now][1] = min(up[f[now][0]][1] + dp[f[now][0]][1] - dp[now][2],up[f[now][0]][0] + dp[f[now][0]][0] - dp[now][1]);
    up[now][0] = up[f[now][0]][1] + dp[f[now][0]][1] - dp[now][2];
  }
  for (auto it = edge[now].begin();it != edge[now].end();it++)
    if (*it != f[now][0])
      calc_up(*it);
}

void doubling() {
  for (int i = 1;i <= n;i++) 
    w[i][0][0][0] = inf,
    w[i][0][0][1] = dp[f[i][0]][0] - dp[i][1],
    w[i][0][1][0] = w[i][0][1][1] = dp[f[i][0]][1] - dp[i][2];
  for (int d = 1;d < 20;d++)
    for (int i = 1;i <= n;i++) {
      int f0 = f[i][d - 1];
      f[i][d] = f[f0][d - 1];
      if (f[i][d]) {
        for (int t1 = 0;t1 < 2;t1++)
          for (int t2 = 0;t2 < 2;t2++) 
            w[i][d][t1][t2] = min(w[f0][d - 1][t1][0] + w[i][d - 1][0][t2],w[f0][d - 1][t1][1] + w[i][d - 1][1][t2]); // t1--up st, t2--down st
      }
    }
}

int lca(int x,int y) {
  if (d[x] > d[y]) swap(x,y);
  for (int i = 19;i >= 0;i--)
    if (d[f[y][i]] >= d[x]) y = f[y][i];
  for (int i = 19;i >= 0;i--)
    if (f[y][i] != f[x][i])
      x = f[x][i],
      y = f[y][i];
  if (x != y) return f[x][0];
  return x;
}

long long query_chain(int x,int y,int sx,int sy) {
  long long a[2],b[2];
  a[sy] = dp[y][sy];
  a[sy ^ 1] = inf;
  for (int i = 19;i >= 0;i--)
    if (d[f[y][i]] >= d[x]) {
      b[0] = min(a[0] + w[y][i][0][0],a[1] + w[y][i][0][1]);
      b[1] = min(a[0] + w[y][i][1][0],a[1] + w[y][i][1][1]);
      a[0] = b[0];
      a[1] = b[1];
      y = f[y][i];
    }
  return a[sx];
}

long long query(int x,int y,int sx,int sy) {
  if (d[x] > d[y]) swap(x,y),swap(sx,sy);
  int l = lca(x,y);
  if (l == x) return query_chain(x,y,sx,sy) + up[x][sx];
  return min(query_chain(l,x,0,sx) + query_chain(l,y,0,sy) - dp[l][0] + up[l][0],query_chain(l,x,1,sx) + query_chain(l,y,1,sy) - dp[l][1] + up[l][1]);
}

char type[10];

int main() {
  //freopen("defense.in","r",stdin);
  //freopen("defense.out","w",stdout);
  scanf("%d%d%s",&n,&m,type);
  for (int i = 1;i <= n;i++) scanf("%d",p + i);
  int u,v;
  for (int i = 1;i < n;i++) {
    scanf("%d%d",&u,&v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  f[1][0] = 0;
  d[1] = 1;
  dfs(1);
  up[1][0] = up[1][1] = 0;
  calc_up(1);
  doubling();
  int a,x,b,y;
  while (m--) {
    scanf("%d%d%d%d",&a,&x,&b,&y);
    long long ans = query(a,b,x,y);
    if (ans < inf) printf("%lld\n",ans);
    else puts("-1");
  }
  return 0;
}
