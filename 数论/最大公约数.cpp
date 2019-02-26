#include<iostream>
using namespace std;
/*
辗转相减法，
gcd(a,b)=gcd(a,b-a),b>a
gcd(4,6)=gcd(4,2)
时间复杂度O(n)
*/
int gcd1(int a,int b){
    if(b<=a){
        return b;
    }
    return gcd1(a,b-a);
}
/*
辗转相除法（欧几里得）
gcd(a,b)=gcd(a,a%b)
时间复杂度O(logn)
*/
int gcd2(int a,int b){
    if(b==0){
        return a;
    }
    return gcd2(b,a%b);
}
int main()
{
    cout<<gcd1(333,999)<<endl;
    cout<<gcd2(999,333)<<endl;
    return 0;
}