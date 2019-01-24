#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int size1=s1.size(),size2=s2.size();
    int high=size1>size2?size1:size2;
    int* ans=new int[high*2]{0};
    int k=high*2-1;
    int i=size1-1;
    int j=size2-1;
    while(i>=0&&j>=0){
        ans[k]=s1[i]-'0'+s2[j]-'0';
        i--;
        j--;
        k--;
    }
    while(i>=0){
        ans[k]=s1[i]-'0';
        k--;
        i--;
    }
    while(j>=0){
        ans[k]=s2[j]-'0';
        k--;
        j--;
    }
    for(int i=high-1;i>=0;i--){
        if(ans[i]>=10){
            ans[i]-=10;
            ans[i-1]+=1;
        }
    }
    int len=high*2;
    for(int i=0;i<len;i++){
        if(ans[i]!=0){
            for(int j=i;j<len;j++){
                cout<<ans[j];
            }   
            break;
        }
    }
    cout<<endl;
    return 0;
}