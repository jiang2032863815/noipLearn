#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int size1=s1.size(),size2=s2.size();
    int high=size1+size2;
    int* ans=new int[high]{0};
    int p=high-1;
    for(int i=size1-1;i>=0;i--){
        int o=p;
        for(int j=size2-1;j>=0;j--){
            ans[o]+=(s1[i]-'0')*(s2[j]-'0');
            o--;
        }
        p--;
    }
    for(int i=high-1;i>=0;i--){
        if(ans[i]>=10){
            ans[i-1]+=ans[i]/10;
            ans[i]%=10;
        }
    }
    for(int i=0;i<high;i++){
        if(ans[i]!=0){
            for(int j=i;j<high;j++){
                cout<<ans[j];
            }
            break;
        }
    }
    cout<<endl;
    return 0;
}