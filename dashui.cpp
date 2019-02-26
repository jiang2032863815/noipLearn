#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> *need = new vector<int>[numCourses];
        for (auto v : prerequisites)
        {
            need[v.first].push_back(v.second);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (need[i].size() == 0)
            {
                q.push(i);
                cout << i << " cando" << endl;
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            cout<<666<<endl;
            int s = q.front();
            cnt++;
            for (int i = 0; i < numCourses; i++)
            {
                if (need[i].size() > 0)
                {
                    for (vector<int>::iterator it = need[i].begin(); it != need[i].end(); it++)
                    {
                        if (*it == s)
                        {
                            need[i].erase(it);
                        }
                    }
                    if (need[i].size() == 0)
                    {
                        cout<<"push"<<i<<endl;
                        q.push(i);
                    }
                }
            }
            cout<<"pop"<<endl;
            q.pop();
        }
        return cnt == numCourses;
    }
};
int main()
{
    Solution s;
    vector<pair<int, int>> v;
    v.push_back(pair<int, int>(1, 0));
    cout << s.canFinish(2, v) << endl;
    return 0;
}