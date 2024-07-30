class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        bool havezero = false;
        int l = 0;
        int midZeroIndex = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 0)
            {
                if (!havezero)
                {
                    midZeroIndex = r;
                }
                else
                {
                    l = midZeroIndex + 1;
                    midZeroIndex = r;
                }
                havezero = true;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};