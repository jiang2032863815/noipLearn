#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mo=1e9+7;
typedef long long ll;

int n,m,f[N],g[N];

int Pow(int x,int y,int p){
	int ans=1;
	for(;y;y>>=1,x=(ll)x*x%p)if(y&1) ans=(ll)ans*x%p;
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1){
		printf("%d\n",Pow(2,m,mo)); return 0;
	}
	if(n==2){
		printf("%d\n",4ll*Pow(3,m-1,mo)%mo); return 0;
	}
	if(n==3&&m==3){
		puts("112"); return 0;
	}
	
	int ans=0,tmp=0;
	//00,11
	{
		tmp=0;
		tmp=Pow(4,n-2,mo);
		tmp=(ll)tmp*Pow(3,m-n,mo)%mo;
		tmp=(ll)tmp*Pow(2,n-1,mo)%mo;
		ans=(ans+2ll*tmp)%mo;
	}
	//000,111
	{
		int k1=1;
		for(int i=1;i<=4&&i<=n;i++) for(int j=1;j<=4&&j<=m;j++) if(i+j-1==4)++k1;
		tmp=k1;
		tmp=(ll)tmp*Pow(4,max(0,n-4),mo)%mo;
		tmp=(ll)tmp*Pow(3,m-max(n,4),mo)%mo;
		tmp=(ll)tmp*Pow(2,n-1,mo)%mo;
		ans=(ans+2ll*tmp)%mo;		
	}
	//011
	{
		memset(f,0,sizeof f); memset(g,0,sizeof g);
		for(int i=1;i<=m;i++) f[i]=(i<=n?5:4); f[m+1]=3; g[m+1]=1;
		for(int i=m;i>=1;i--) g[i]=(ll)g[i+1]*(f[i]-1)%mo;
		int k1=0,k2=0;
		for(int i=4;i<=m-1;i++){
			int cur=(ll)(f[i]-1)*f[i+1]%mo*g[i+2]%mo;
			k1=(k1+cur)%mo;
		}
		k1=(ll)k1*Pow(2,n-1,mo)%mo;
		k2=(ll)f[m]*f[m+1]%mo*Pow(2,n-2,mo)%mo;
		ans=(0ll+ans+k1+k2)%mo;
	}
	//001
	{
		if(n==3){
			int k1=4ll*Pow(3,m-4,mo)%mo*Pow(2,n-1,mo)%mo;
			ans=(ans+k1)%mo;
		}else{
			memset(f,0,sizeof f); memset(g,0,sizeof g);
			for(int i=1;i<=n;i++) f[i]=(i<=n?5:4); f[n+1]=(n==m?3:4); g[n+1]=1;
			for(int i=n;i>=1;i--) g[i]=(ll)g[i+1]*(f[i]-1)%mo;
			int k1=0,k2=0;
			for(int i=4;i<=n-1;i++){
				int cur=(ll)(f[i]-1)*f[i+1]%mo*g[i+2]%mo;
				k1=(k1+cur)%mo;
			}
			int tmpvalue=(n==m)?Pow(2,n-2,mo):(ll)Pow(3,m-n-1,mo)*Pow(2,n-1,mo)%mo;
			k1=(ll)k1*Pow(3,m-n,mo)%mo*Pow(2,n-1,mo)%mo;
			k2=(ll)f[n]*f[n+1]%mo*tmpvalue%mo;
			ans=(0ll+ans+k1+k2)%mo;
		}
	}
	printf("%d\n",2ll*ans%mo);
	return 0;
}

