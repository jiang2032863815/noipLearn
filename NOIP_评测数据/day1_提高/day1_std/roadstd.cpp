#include<cstdio>
int n;
int main()
{
	freopen("../samples/road2.in","r",stdin);
	freopen("../samples/road2.ans","w",stdout);
	int i,ans=0,las=0,w;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&w);
		if(w>las)
			ans+=w-las;
		las=w;
	}
	printf("%d\n",ans);
	return 0;
} 
