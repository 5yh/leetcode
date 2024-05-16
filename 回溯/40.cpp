class Solution
{
public:
    void huisu(vector<vector<int>> &ans, vector<int> &now, int shengyu, vector<int> &candidates, int beforei)
    {
        if (shengyu == 0)
        {
            ans.emplace_back(now);
            for (int num : now)
            {
                std::cout << num << std::endl;
            }
            return;
        }
        for (int i = beforei + 1; i < candidates.size(); i++)
        {
            if (i > beforei + 1 && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] <= shengyu)
            {
                now.emplace_back(candidates[i]);
                huisu(ans, now, shengyu - candidates[i], candidates, i);
                now.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        // for (int num : candidates)
        // {
        //     std::cout << num << std::endl;
        // }
        vector<vector<int>> ans;
        vector<int> now;
        huisu(ans, now, target, candidates, -1);
        return ans;
    }
};