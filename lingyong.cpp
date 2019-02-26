#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int T, C;

struct Node
{
    int p, n;
    bool operator<(Node t) const
    {
        return p > t.p;
    }
} e[25];

void deal()
{
    int pos, ans = 0, finish = true, left, cnt, num;
    for (int i = 1; i <= T; ++i)
    {
        if (e[i].p >= C)
        {
            ans += e[i].n;
        }
        else
        {
            pos = i;
            finish = false;
            break;
        }
    }
    while (!finish)
    {
        finish = true;
        left = C;
        for (int i = pos; i <= T; ++i)
        {
            if (e[i].n > 0 && e[i].p <= left)
            {
                num = left / e[i].p;
                cnt = min(num, e[i].n);
                e[i].n -= cnt;
                left -= cnt * e[i].p;
            }
        }
        for (int i = T; i >= pos; --i)
        {
            if (e[i].n > 0 && left > 0)
            {
                --e[i].n;
                left -= e[i].p;
            }
        }
        if (left <= 0)
        {
            ++ans, finish = false;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d %d", &T, &C);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%d %d", &e[i].p, &e[i].n);
    }
    sort(e + 1, e + 1 + T);
    deal();
    return 0;
}