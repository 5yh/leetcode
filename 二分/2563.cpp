class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        // 先排序
        sort(nums.begin(), nums.end());
        // 对于每一个单独算
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            int aa = lower_bound(nums.begin(), nums.begin() + j, upper - nums[j] + 1) - 1 - nums.begin();
            int bb = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j] + 1) - nums.begin();
            ans += aa - bb;
        }
        return ans;
    }
};