#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int r=n;
    //求比n小其与n互质数的个数
    //欧拉函数
    //24=2*2*2*3=2^3*3^1
    //个数为24*(1-1/2)*(1-1/3)=(24-24/2)*（1-1/3）=24-24/3-24/2+24/6
    int x = 2;
    vector<int> list;
    int before = 1;
    while (n > 1)
    {
        if (n % x == 0)
        {
            n /= x;
            if (x != before)
            {
                list.push_back(x);
            }
            before=x;
        }
        else
        {
            x++;
        }
    }
    double ans=(double)r;
    int size=list.size();
    for(int i=0;i<size;i++){
        ans*=(1.0-1.0/list[i]);
    }
    cout<<ans<<endl;
    return 0;
}