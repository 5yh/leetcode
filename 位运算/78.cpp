// 回溯法
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> t;
    void dfs(int cur, vector<int> &shuzu)
    {
        if (cur == shuzu.size())
        {
            ans.push_back(t);
            return;
        }
        t.push_back(shuzu[cur]);
        dfs(cur + 1, shuzu);
        t.pop_back();
        dfs(cur + 1, shuzu);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // 返回子集
        // 返回遍历
        // dfs遍历
        dfs(0, nums);
        return ans;
    }
};