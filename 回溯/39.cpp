class Solution
{
public:
    void huisu(vector<vector<int>> &ans, vector<int> &now, int shengyu, vector<int> &candidates, int beforei)
    {
        if (shengyu == 0)
        {
            ans.emplace_back(now);
        }
        for (int i = beforei; i < candidates.size(); i++)
        {
            if (candidates[i] <= shengyu)
            {
                now.emplace_back(candidates[i]);
                huisu(ans, now, shengyu - candidates[i], candidates, i);
                now.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> now;
        huisu(ans, now, target, candidates, 0);
        return ans;
    }
};