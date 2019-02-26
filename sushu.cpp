#include <iostream>
using namespace std;
int n;
bool *use;
int *list;
bool *exist;
void search(int a)
{
    if (a >= n)
    {
        if (!exist[list[1] + list[n]])
        {
            for (int i = 1; i <= n; i++)
            {
                cout << list[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!use[i])
        {

            if (!exist[list[a] + i])
            {
                use[i] = true;
                list[a + 1] = i;
                search(a + 1);
                use[i] = false;
            }
        }
    }
}
int main()
{
    cin >> n;
    use = new bool[n + 1]{false};
    list = new int[n + 1]{0};
    exist = new bool[n * 2 + 1]{false};
    for (int k = 3; k <= n * 2; k++)
    {
        for (int i = 2; i < k; i++)
        {
            if (k % i == 0)
            {
                exist[k] = true;
            }
        }
    }
    use[1] = true;
    list[1] = 1;
    search(1);
    return 0;
}