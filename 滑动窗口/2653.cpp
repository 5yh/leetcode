class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        const int BIAS = 50;
        int cnt[BIAS * 2 + 1]{};
        int n = nums.size();
        for (int i = 0; i < k - 1; i++)
        {
            cnt[BIAS + nums[i]]++;
        }
        vector<int> ans(n - k + 1);
        for (int i = k - 1; i < n; i++)
        {
            cnt[BIAS + nums[i]]++;
            int left = x; // 第x小的数
            for (int j = 0; j < BIAS; j++)
            {
                left -= cnt[j];
                if (left <= 0)
                {
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }
            cnt[BIAS + nums[i - k + 1]]--;
        }
        return ans;
    }
};