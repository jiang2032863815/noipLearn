#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
const int maxn=100010;
int n,m;
struct edge{int to,len;edge*next;}E[maxn*2],*ne=E,*fir[maxn];
void link(int u,int v,int l){*ne=(edge){v,l,fir[u]};fir[u]=ne++;}
int f[maxn],g[maxn],l[maxn];
int chk(int M,int c,int d){
	int s=0;
	for(int i=c,j=-1;--i>j;)if(i!=d){
		if(l[i]>=M)s++;
		else{
			while(++j<i&&(j==d||l[j]+l[i]<M));
			if(j<i)s++;
		}
	}
	return s;
}
int b[maxn];
int dfs(int M,int i,int fa){
	f[i]=0;
	for(edge*e=fir[i];e;e=e->next)if(e->to!=fa){
		dfs(M,e->to,i);
		f[i]+=f[e->to];
	}
	int c=0;
	for(edge*e=fir[i];e;e=e->next)if(e->to!=fa)
		l[c++]=g[e->to]+e->len;
	std::sort(l,l+c);
	int s=chk(M,c,-1),left=-1,right=c,mid;
	while(right-left>1)chk(M,c,mid=left+right>>1)<s?right=mid:left=mid;
	f[i]+=s;
	g[i]=left<0?0:l[left];
	return f[i];
}
int main(){
	scanf("%d%d",&n,&m);
	int left=0,right=1,mid;
	for(int i=1,u,v,l;i<n;i++)scanf("%d%d%d",&u,&v,&l),link(u,v,l),link(v,u,l),right+=l;
	//fprintf(stderr,"%lfs\n",clock()/(double)CLOCKS_PER_SEC);
	while(right-left>1)dfs(mid=left+right>>1,1,0)>=m?left=mid:right=mid;
	printf("%d\n",left);
	//fprintf(stderr,"%lfs\n",clock()/(double)CLOCKS_PER_SEC);
}
