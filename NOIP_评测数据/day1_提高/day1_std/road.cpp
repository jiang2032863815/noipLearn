#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Hzy(o) freopen(o".in", "r", stdin), freopen(o".out", "w", stdout)
using namespace std;
const int N = 100010;
struct Node {
	int val, pos;
	bool operator < (const Node & p) const { return val < p.val; }
}a[N];
bool vis[N];
int n, ans;
int main() {
	Hzy("road");
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].val);
		a[i].pos = i;
	}
	sort(a + 1, a + n + 1);
	int cnt = 0, t1, t2;
	for(int i = n; i >= 1; --i) {
		t1 = a[i].pos - 1;
		t2 = a[i].pos + 1;
		vis[a[i].pos] = 1;
		cnt++;
		if(t1 > 0 && t1 <= n && vis[t1]) cnt--;
		if(t2 > 0 && t2 <= n && vis[t2]) cnt--;
		ans += (a[i].val - a[i - 1].val) * cnt;
	}
	cout << ans << endl;
	return 0;
}
