class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int l = 0;
        int ans = 0;
        int midpos = 0;
        int n = nums.size();
        bool havezero = false;
        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 0)
            {
                if (!havezero)
                {
                    midpos = r;
                }
                else
                {
                    l = midpos + 1;
                    midpos = r;
                }
                havezero = true;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};