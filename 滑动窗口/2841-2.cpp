class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long ans = 0, sum = 0;
        unordered_map<int, int> cnt;
        // 先放k-1个进去
        for (int i = 0; i < k - 1; i++)
        {
            cnt[nums[i]]++;
            sum += nums[i];
        }

        for (int i = k - 1; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
            sum += nums[i];
            if (cnt.size() >= m)
            {
                if (sum > ans)
                {
                    ans = sum;
                }
            }
            int out = nums[i - k + 1];
            sum -= out;
            // 新的子数组没有out，erase掉
            if (--cnt[out] == 0)
            {
                cnt.erase(out);
            }
        }
        return ans;
    }
};