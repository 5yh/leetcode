class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int len = nums.size();
        int zongcnt1 = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 1)
            {
                zongcnt1++;
            }
        }
        int cnt1 = 0;
        int ans = INT_MAX;
        for (int i = 0; i < zongcnt1 - 1; i++)
        {
            if (nums[i] == 1)
            {
                cnt1++;
            }
        }
        for (int i = zongcnt1 - 1; i < nums.size() + zongcnt1; i++)
        {
            if (nums[i % nums.size()] == 1)
            {
                cnt1++;
            }
            if (ans > zongcnt1 - cnt1)
            {
                ans = zongcnt1 - cnt1;
            }
            if (nums[(i - zongcnt1 + 1) % nums.size()] == 1)
            {
                cnt1--;
            }
        }
        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};