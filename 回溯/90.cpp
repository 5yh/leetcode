class Solution
{
public:
    void search(vector<vector<int>> &ans, vector<int> &now, int cur, vector<int> &nums, vector<bool> &vis)
    {
        // if (cur == now.size() - 1)
        // {
        //     ans.push_back(now);
        //     return;
        // }
        ans.push_back(now);
        for (int i = cur; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i] && vis[i - 1] == false)
            {
                continue;
            }
            vis[i] = true;
            now.push_back(nums[i]);
            search(ans, now, i + 1, nums, vis);
            vis[i] = false;
            now.pop_back();
            // search(ans, now, i + 1, nums, vis);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> now;
        vector<bool> vis(nums.size(), false);
        search(ans, now, 0, nums, vis);
        return ans;
    }
};
// 搞一个vis
// 若等于前一个且前一个没有被访问，说明是重复的不要