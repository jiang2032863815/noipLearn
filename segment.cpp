#include<iostream>
using namespace std;
struct line{
	int start,end;
};
line* a;
void quickSort(int s,int e)
{
	while(s<e){
		int low=s;
		int high=e;
		line key=a[low];
		while(low<high){
			while(low<high&&a[high].end>=key.end){
				high--;
			}
			a[low]=a[high];
			while(low<high&&a[low].end<=key.end){
				low++;
			}
			a[high]=a[low];
		}
		a[low]=key;
		quickSort(s,low-1);
		s=low+1;
	}
}
int main()
{
	int n;
	cin>>n;
	a=new line[n];
	for(int i=0;i<n;i++){
		line l;
		cin>>l.start>>l.end;
		a[i]=l;
	}
	quickSort(0,n-1);
	int k=1;
    int end=a[0].end;
	for(int i=1;i<n;i++){
		if(a[i].start>=end){
			k++;
            end=a[i].end;
		}
	}
	cout<<k<<endl;
	return 0;
}