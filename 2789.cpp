class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        long long ans = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            ans = nums[i] <= ans ? ans + nums[i] : num[i];
        }
        return ans;
    }
};