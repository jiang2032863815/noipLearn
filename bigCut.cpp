#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int size1=s1.size(),size2=s2.size(),high=size1>size2?size1:size2;
    int* ans=new int[high+1]{0};
    int k=high;
    int i=size1-1;
    int j=size2-1;
    while(i>=0&&j>=0){
        ans[k]=(s1[i]-'0')-(s2[j]-'0');
        i--;
        j--;
        k--;
    }
    while(i>=0){
        ans[k]=s1[i]-'0';
        i--;
        k--;
    }
    while(j>=0){
        ans[k]=s2[j]-'0';
        j--;
        k--;
    }
    for(int i=high;i>=0;i--){
        if(ans[i]<0){
            ans[i]+=10;
            ans[i-1]--;
        }
    }
    if(high==1&&ans[0]==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<=high;i++){
        if(ans[i]!=0){
            for(int j=i;j<=high;j++){
                cout<<ans[j];
            }
            break;
        }
    }
    cout<<endl;
    return 0;
}