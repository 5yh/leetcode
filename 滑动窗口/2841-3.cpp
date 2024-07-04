class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long ans = 0, sum = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < k - 1; i++)
        { // 先统计 k-1 个数
            sum += nums[i];
            cnt[nums[i]]++;
        }
        for (int i = k - 1; i < nums.size(); i++)
        {
            sum += nums[i]; // 再添加一个数就是 k 个数了
            cnt[nums[i]]++;
            if (cnt.size() >= m)
                ans = max(ans, sum);

            int out = nums[i - k + 1];
            sum -= out; // 下一个子数组不包含 out，移出窗口
            if (--cnt[out] == 0)
                cnt.erase(out);
        }
        return ans;
    }
};
