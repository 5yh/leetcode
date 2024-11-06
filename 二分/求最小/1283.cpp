class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        // 只能每一次都算一下
        int l = 0;
        int ans = -1;
        int r = *max_element(nums.begin(), nums.end()) + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            int total = 0;
            for (int num : nums)
            {
                total += (num - 1) / m + 1;
            }
            if (total <= threshold)
            {
                ans = m;
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return ans;
    }
};