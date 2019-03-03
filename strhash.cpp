#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ULL;
ULL power[1000000];
ULL sum[1000000];
const int b=233;
int main(){
    power[0]=1;
    for(int i=1;i<1000000;i++){
        power[i]=power[i-1]*b;       
    }
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    sum[0]=0;
    for(int i=1;i<=m;i++){
        sum[i]=sum[i-1]*b+s2[i-1];
    }
    ULL s=0;
    for(int i=1;i<=n;i++){
        s=s*b+s1[i-1];
    }
    int ans=0;
    for(int i=0;i<=m-n;i++){
        if(s==sum[i+n]-sum[i]*power[n])++ans;
    }
    cout<<ans<<endl;
}