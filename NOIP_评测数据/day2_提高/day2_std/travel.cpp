#include <stdio.h>
#include <algorithm>

const int MAXN = 300005;

int n, m;

struct edge {
	int u, v, id;
};

bool operator < (const edge &a, const edge &b) {
	return a.u < b.u || (a.u == b.u && a.v < b.v);
}

edge edges[MAXN * 2];
edge *first[MAXN];

int stack[MAXN];
int stack_eid[MAXN];
bool instack[MAXN];
int top;
bool found;

bool is_on_cycle[MAXN];

void dfs(int u, int last) {
	stack[++top] = u;
	instack[u] = true;
	for (edge *e = first[u]; e->u == u; e++) {
		int v = e->v;
		if (v == last) continue;
		if (instack[v]) {
			found = true;
			is_on_cycle[e->id] = true;
			while (stack[top] != v) {
				is_on_cycle[stack_eid[top - 1]] = true;
				--top;
			}
			return;
		}
		stack_eid[top] = e->id;
		dfs(v, u);
		if (found) return;
	}
	instack[u] = false;
	--top;
}

int ans_idx;

bool visit[MAXN];
bool del;

void dfs(int u) {
	printf("%d%c", u, " \n"[++ans_idx == n]);
	visit[u] = true;
	++top;
	bool done = false;
	for (edge *e = first[u]; e->u == u; e++) {
		int v = e->v;
		if (visit[v]) continue;
		edge *e1 = e + 1;
		while (e1->u == u && visit[e1->v]) ++e1;
		if (e1->u == u) {
			stack[top] = e1->v;
		} else {
			--top;
			done = true;
		}
		if (!del && is_on_cycle[e->id] && v > stack[top]) {
			del = true;
		} else {
			dfs(v);
		}
	}
	if (!done) --top;
}

int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) {
		return puts("1"), 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[i * 2] = (edge){u, v, i};
		edges[i * 2 + 1] = (edge){v, u, i};
	}
	std::sort(edges, edges + 2 * m);
	first[1] = edges;
	for (int i = 1; i < 2 * m; i++) {
		if (edges[i].u != edges[i - 1].u) {
			first[edges[i].u] = edges + i;
		}
	}
	dfs(1, 0);
	top = 0;
	stack[0] = n + 1;
	dfs(1);
}
