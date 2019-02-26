#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=600,M=51000;
int f[M],n,m,a[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1); m=0;
	for (int i=1;i<=n;i++) m=max(m,a[i]);
	memset(f,0x00,sizeof f); f[0]=1; int ans=0;
	for (int i=1;i<=n;i++){
		if (f[a[i]]) continue; ans++;
		for (int j=a[i];j<=m;j++) f[j]|=f[j-a[i]];
	}
	printf("%d\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}