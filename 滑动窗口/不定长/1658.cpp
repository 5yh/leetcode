class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int summ = 0;

        for (int i = 0; i < n; i++)
        {
            summ += nums[i];
        }
        int shengyu = summ - x;
        if (shengyu < 0)
            return -1;
        int l = 0;
        int ans = -1;
        int summ1 = 0;
        for (int r = 0; r < n; r++)
        {
            summ1 += nums[r];
            while (summ1 > shengyu)
            {
                summ1 -= nums[l];
                l++;
            }
            if (summ1 == shengyu)
            {
                ans = max(ans, r - l + 1);
            }
        }
        return ans < 0 ? -1 : n - ans;
    }
};