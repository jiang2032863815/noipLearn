#include<iostream>
#include<algorithm>
using namespace std;
int* N;
int* S;
void quickSort(int start,int end)
{
    while(start<end){
        int low=start;
        int high=end;
        int key=N[low];
        int keyS=S[low];
        while(low<high){
            while(low<high&&N[high]>=key){
                high--;
            }
            N[low]=N[high];
            S[low]=S[high];
            while(low<high&&N[low]<=key){
                low++;
            }
            N[high]=N[low];
            S[high]=S[low];
        }
        N[low]=key;
        S[low]=keyS;
        quickSort(start,low-1);
        start=low+1;
    }
}
int* f;
int main()
{
    int a;
    cin>>a;
    N=new int[a];
    S=new int[a];
    for(int i=0;i<a;i++){
        cin>>N[i]>>S[i];
    }
    quickSort(0,a-1);
    f=new int[a];
    for(int i=0;i<a;i++){
        f[i]=1;
    }
    int ans=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<i;j++){
            if(S[i]>=S[j]){
                f[i]=max(f[i],f[j]+1);
            }
        }
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}