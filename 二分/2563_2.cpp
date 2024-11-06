class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            long long aa = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]) - 1 - nums.begin();
            long long bb = lower_bound(nums.begin(), nums.begin() + j, upper - nums[j] + 1) - 1 - nums.begin();
            cnt += bb - aa;
        }
        return cnt;
    }
};