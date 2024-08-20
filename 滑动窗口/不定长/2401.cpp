class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int or_ = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            while (nums[r] & or_)
            {
                or_ ^= nums[l++];
            }
            or_ |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};