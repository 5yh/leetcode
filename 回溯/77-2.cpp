class Solution
{
public:
    vector<int> tmpans;
    vector<vector<int>> ans;
    void dfs(int k, int cur, int n)
    {
        // cout << k << ' ' << cur << ' ' << n << endl;
        if (tmpans.size() + (n - cur + 1) < k)
        {
            return;
        }
        if (tmpans.size() == k)
        {
            // vector<int> kaobei = tmpans;
            // ans.push_back(kaobei);
            ans.push_back(tmpans);
            return;
        }
        if (cur == n + 1)
        {
            return;
        }
        tmpans.push_back(cur);
        dfs(k, cur + 1, n);
        tmpans.pop_back();
        dfs(k, cur + 1, n);
    }
    vector<vector<int>> combine(int n, int k)
    {
        dfs(k, 1, n);
        return ans;
    }
};