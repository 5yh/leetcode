class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int l = 0;
        int ans = 0;
        int n = nums.size();
        int summ = 0;
        int vis[100010] = {0};
        for (int r = 0; r < n; r++)
        {
            while (vis[nums[r]])
            {
                vis[nums[l]]--;
                summ -= nums[l];
                l++;
            }
            vis[nums[r]]++;
            summ += nums[r];
            ans = max(ans, summ);
        }
        return ans;
    }
};