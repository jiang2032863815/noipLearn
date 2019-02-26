#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int* a=new int[n];
    int* b=new int[m];
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[i]=t;
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        b[i]=t;
    }
    int ans=0;
    int x=-1,y=-1;
    for(int i=0;i<n&&i<m;i++){
        int ai=a[i];
        for(int t=i;t>=0&&t>y;t--){
            if(b[t]==ai){
                ans++;
                x=i;
                y=t;
            }
        }
        int bi=b[i];
        for(int t=i;t>=0&&t>x;t--){
            if(a[t]==bi){
                ans++;
                y=i;
                x=t;
            }
        }
    }
    for(int i=m;i<n;i++){
        int ai=a[i];
        for(int t=m-1;t>=0&&t>y;t--){
            if(b[t]==ai){
                ans++;
                x=i;
                y=t;
            }
        }
    }
    for(int i=n;i<m;i++){
        int bi=b[i];
        for(int t=n-1;t>=0&&t>x;t--){
            if(a[t]==bi){
                ans++;
                y=i;
                x=t;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}