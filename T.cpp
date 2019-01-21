#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int a;
    cin>>a;
    vector<int> list;
    int i=2;
    while(a!=1){
        if(a%i==0){
            list.push_back(i);
            a/=i;
        }else{
            i++;
        }
    }
    int ans=1;
    int temp=list[0];
    int size=list.size();
    int c=1;
    for(int j=1;j<size;j++){
        if(list[j]==temp){
            c++;
        }else{
            ans*=(c+1);
            temp=list[j];
            c=1;
        }
    }
    ans*=(c+1);
    cout<<ans<<endl;
    return 0;
}