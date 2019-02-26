#include<iostream>
#include<string>
using namespace std;
string A;
string B;
int sizea,sizeb;
int** result;
int solve(int i,int j)
{
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(i<0&&j<0){
        return 0;
    }
    if(i==0&&j==0){
        if(A[i]==B[j]){
            return 0;
        }else{
            return 1;
        }
    }
    if(result[i][j]>=0){
        return result[i][j];
    }
    if(A[i]==B[j]){
        result[i][j]=solve(i-1,j-1);
        return result[i][j];
    }
    int a=solve(i-1,j-1)+1;
    int b=solve(i-1,j)+1;
    int c=solve(i,j-1)+1;
    if(a>b){
        a=b;
    }
    if(a>c){
        a=c;
    }
    result[i][j]=a;
    return a;
}
int main()
{
    cin>>A>>B;
    sizea=A.size();
    sizeb=B.size();
    result=new int*[sizea];
    for(int i=0;i<sizea;i++){
        result[i]=new int[sizeb];
        for(int j=0;j<sizeb;j++){
            result[i][j]=-1;
        }
    }
    cout<<solve(sizea-1,sizeb-1)<<endl;
    return 0;
}