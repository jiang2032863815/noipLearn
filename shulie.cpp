#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	//4 2 4 5 1
	//1 1 2 4 4 5
	int n,m;
	cin>>n>>m;
	int* a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0;
	int j=n-1;
	int ans=1;
	int c=0;
	//1 2 4 4 5
	int total=0;
	while(c<n){
		if(total+a[i]+a[j]<=m){
			total+=a[i]+a[j];
			c+=2;
			i++;
			j--;
		}else if(a[i]>a[j]&&total+a[i]<=m){
			total+=a[i];
			i++;
			c++;
		}else if(total+a[j]<=m){
			j--;
			total+=a[j];
			c++;
		}else{
			ans++;
			total=0;
		}
	}
	cout<<ans<<endl;
}