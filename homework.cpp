#include <bits/stdc++.h>
using namespace std;

struct PII
{
    int score, day;
} p[1010101];
bool cmp(PII a, PII b)
{
    if (a.score == b.score)
        return a.day > b.day;
    return a.score > b.score;
}
int n;
int pre[1010101];
bool vis[1010100];
int father(int day)
{
    cout << "f(" << day << ")" << endl;
    if (!vis[day])
    {
        cout << "f(" << day << "),return " << day << endl;
        return day;
    }
    pre[day] = father(pre[day]);
    cout << "f(" << day << "),return " << pre[day] << endl;
    return pre[day];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].day, &p[i].score);
    sort(p, p + n, cmp);
    for (int i = 1; i <= 700000; i++)
        pre[i] = i - 1, vis[i] = false;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ok = father(p[i].day);
        if (ok == 0)
            continue;
        vis[ok] = true;
        ans += p[i].score;
        cout<<"+"<<p[i].score<<endl;
    }
    printf("%d\n", ans);
}