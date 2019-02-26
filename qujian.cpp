#include<iostream>
using namespace std;
struct S{
    int start,end;
};
int main()
{
    int n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    S* a=new S[n];
    for(int i=0;i<n;i++){
        cin>>a[i].start>>a[i].end;
        S temp=a[i];
        int j=i-1;
        while(j>=0&&a[j].end>temp.end){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    int ans=1;
    int end=a[0].end;
    for(int i=1;i<n;i++){
        if(a[i].start>=end){
            ans++;
            end=a[i].end;
        }
    }
    cout<<ans<<endl;
    return 0;
}