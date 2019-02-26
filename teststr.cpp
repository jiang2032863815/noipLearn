#include<iostream>
#include<string>
using namespace std;
void change(string& s)
{
    s[0]='6';
}
int main()
{
    string s="455";
    change(s);
    cout<<s<<endl;
    return 0;
}