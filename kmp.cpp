#include<iostream>
#include<string>
using namespace std;
bool kmp(string s,string p){
	int slen=s.size();
	int plen=p.size();
	int j=0;
	int* next=new int[plen]{0};
	for(int i=1;i<plen;i++){
		while(j>0&&p[i]!=p[j]){
			j=next[j-1];
		}
		if(p[i]==p[j]){
			j++;
		}
		next[i]=j;
	}
	j=0;
	for(int i=0;i<slen;i++){
		while(j>0&&s[i]!=p[j]){
			j=next[j-1];
		}
		if(s[i]==p[j]){
			j++;
		}
		if(j==plen){
			cout<<(i-j+1)<<endl;
			return true;
		}
	}
	return false;
}
int main(){
	string s,p;
	cin>>s>>p;
	cout<<(kmp(s,p)?"true":"false")<<endl;
	return 0;
}