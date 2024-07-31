class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> map1;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            map1[nums[r]]++;
            if (map1[nums[r]] > k)
            {
                while (map1[nums[r]] > k)
                {
                    map1[nums[l]]--;
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};