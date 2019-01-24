#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int size1=s1.size();
    int size2=s2.size();
    int* a=new int[size1];
    int* b=new int[size2];
    for(int i=0;i<size1;i++){
        a[i]=s1[i]-'0';
    }
    for(int i=0;i<size2;i++){
        b[i]=s2[i]-'0';
    }
    int* ans=new int[size1]{0};
    int n=0;
    for(int i=size2-1;i<size1;i++){
        int c=0;
        for(;;){
            bool flag=true;
            if(i-n+1<size2){
                flag=false;
            }else if(i-n+1==size2){
                for(int t=n,t2=0;t<=i&&t2<size2;t++,t2++){
                    if(a[t]>b[t2]){
                        break;
                    }else if(a[t]<b[t2]){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag){
                break;
            }
            c++;
            for(int j=i,k=size2-1;j>=n&&k>=0;j--,k--){
                a[j]-=b[k];
                if(a[j]<0){
                    a[j]+=10;
                    a[j-1]--;
                }
            }
            for(int j=n;j<=i;j++){
                if(a[j]<=0){
                    n++;
                }else{
                    break;
                }
            }
        }
        ans[i]=c;
    }
    bool f=false;
    for(int i=0;i<size1;i++){
        if(ans[i]!=0){
            for(int j=i;j<size1;j++){
                cout<<ans[j];
                f=true;
            }
            break;
        }
    }
    if(!f){
        cout<<0;
    }
    cout<<endl;
    return 0;
}