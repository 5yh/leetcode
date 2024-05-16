class Solution
{
public:
    void digui(vector<vector<int>> &ans, vector<int> &now, int first, int n)
    {
        if (first == n)
        {
            ans.emplace_back(now);
            return;
        }
        else
        {
            for (int i = first; i < n; i++)
            {
                swap(now[i], now[first]);
                digui(ans, now, first + 1, n);
                swap(now[i], now[first]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        digui(ans, nums, 0, (int)nums.size());
        return ans;
    }
};