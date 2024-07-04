class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans, sum;
        unordered_map<int, int> cnt;
        for (int i = 0; i < k - 1; i++)
        {
            sum += nums[i];
            cnt[nums[i]]++;
        }
        for (int i = k - 1; i < nums.size(); i++)
        {
            sum += nums[i];
            cnt[nums[i]]++;
            if (cnt.size() == k)
            {
                if (sum > ans)
                {
                    ans = sum;
                }
            }
            int out = nums[i + 1 - k];
            sum -= out;
            cnt[nout]--;
            if (cnt[out] == 0)
            {
                cnt.erase(out);
            }
        }
        return ans;
    }
};