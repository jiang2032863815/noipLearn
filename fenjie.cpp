#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=2;
    while(n>1){
        if(n%i==0){
            n/=i;
            cout<<i<<" ";
        }else{
            i++;
        }
    }
    cout<<endl;
    return 0;
}