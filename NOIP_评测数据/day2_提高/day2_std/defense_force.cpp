#pragma GCC diagnostic error "-std=c++11"
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int f[300100],p[300100];
long long dp[300100][3];
int a,x,b,y,n,m;
const long long inf = 1e18;

vector<int> edge[300100];

void dfs(int now) {
  dp[now][1] = p[now];
  dp[now][0] = 0;
  for (auto it = edge[now].begin();it != edge[now].end();it++)
    if (*it != f[now]) {
      f[*it] = now;
      dfs(*it);
      dp[now][1] += dp[*it][2];
      dp[now][0] += dp[*it][1];
    }
  if (a == now) dp[now][x ^ 1] = inf;
  if (b == now) dp[now][y ^ 1] = inf;
  dp[now][2] = min(dp[now][0],dp[now][1]);
}

long long query() {
  dfs(1);
  return dp[1][2];
}

char type[10];

int main() {
  //freopen("defense.in","r",stdin);
  //freopen("defense.ans","w",stdout);
  scanf("%d%d%s",&n,&m,type);
  for (int i = 1;i <= n;i++) scanf("%d",p + i);
  int u,v;
  for (int i = 1;i < n;i++) {
    scanf("%d%d",&u,&v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  while (m--) {
    scanf("%d%d%d%d",&a,&x,&b,&y);
    long long ans = query();
    if (ans < inf) printf("%lld\n",query());
    else puts("-1");
  }
  return 0;
}
