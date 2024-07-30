class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int l = 0;
        int ans = 0;
        int n = nums.size();
        vector<int> qianzhuihe(n + 1);
        for (int i = 1; i <= n; i++)
        {
            qianzhuihe[i] += qianzhuihe[i - 1];
            qianzhuihe[i] += nums[i - 1];
        }
        unordered_set<int> set1;
        for (int r = 0; r < n; r++)
        {
            while (set1.count(nums[r]))
            {
                set1.erase(nums[l]);
                l++;
            }
            set1.emplace(nums[r]);
            ans = max(ans, qianzhuihe[r + 1] - qianzhuihe[l]);
        }
        return ans;
    }
};