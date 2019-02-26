#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstring>
const int maxn=100010;
int n,m;
struct edge{int to,len;edge*next;}E[maxn*2],*ne=E,*fir[maxn];
void link(int u,int v,int l){*ne=(edge){v,l,fir[u]};fir[u]=ne++;}
int f[maxn],g[maxn],l[maxn];
int b[maxn],bl[maxn*2];
void rsort(int*a,int n){
	int d=0;while((1<<d)<n)d++;
	for(int i=0;i<30;i+=d){
		memset(bl,0,sizeof(*bl)<<d);
		for(int j=0;j<n;j++)bl[(a[j]>>i&(1<<d)-1)+1]++;
		for(int j=0;j<1<<d;j++)bl[j+1]+=bl[j];
		for(int j=0;j<n;j++)b[bl[a[j]>>i&(1<<d)-1]++]=a[j];
		memcpy(a,b,sizeof(*a)*n);
	}
}
int dfs(int M,int v,int fa){
	f[v]=0;
	for(edge*e=fir[v];e;e=e->next)if(e->to!=fa){
		dfs(M,e->to,v);
		f[v]+=f[e->to];
	}
	int c=0;
	for(edge*e=fir[v];e;e=e->next)if(e->to!=fa)
		l[c++]=g[e->to]+e->len;
	if(c<64)std::sort(l,l+c);
	else rsort(l,c);
	int s=0,t=0,la=c;
	for(int i=c,j=-1;--i>j;s++){
		if(l[i]>=M)la=i;
		else{
			while(++j<i&&l[i]+l[j]<M)t=l[j];
			if(j==i){t=l[la-1];break;}
			if(i&&l[i-1]+l[j]<M)la=i;
		}
	}
	f[v]+=s;g[v]=t;
	return f[v];
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
