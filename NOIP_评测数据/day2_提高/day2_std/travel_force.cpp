#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAXN = 300005;

int n, m;

struct data {
	int u, v, id;
};

bool operator < (const data &a, const data &b) {
	return a.u < b.u || (a.u == b.u && a.v < b.v);
}

data _edges[MAXN * 2];
data *first[MAXN];

int ans[MAXN];
int dfsseq[MAXN];
int visit[MAXN];

int del_e;
int dfs_idx;
bool ok;
bool fail;

#define visit_id (del_e + 1)

void dfs(int x) {
	if (!ok) {
		if (x < ans[dfs_idx]) {
			ok = true;
		} else if (x > ans[dfs_idx]) {
			fail = true;
			return;
		}
	}
	dfsseq[dfs_idx++] = x;
	visit[x] = visit_id;
	for (data *d = first[x]; d->u == x; d++) if (d->id != del_e) {
		int y = d->v;
		if (visit[y] == visit_id) continue;
		dfs(y);
		if (fail) return;
	}
}



int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		_edges[i * 2] = (data){u, v, i};
		_edges[i * 2 + 1] = (data){v, u, i};
	}
	std::sort(_edges, _edges + 2 * m);
	first[1] = _edges;
	for (int i = 1; i < 2 * m; i++) {
		if (_edges[i].u != _edges[i - 1].u) {
			first[_edges[i].u] = _edges + i;
		}
	}
	ans[0] = 2;
	if (n == m) {
		for (int i = 0; i < m; i++) {
			del_e = i;
			dfs_idx = 0;
			ok = false;
			fail = false;
			dfs(1);
			if (dfs_idx == n && ok && !fail) {
				memcpy(ans, dfsseq, n * sizeof(int));
			}
		}
	} else {
		del_e = -2;
		dfs(1);
		memcpy(ans, dfsseq, n * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}
}
