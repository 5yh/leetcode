class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int l = -1;
        int r = nums.size();
        int m = 0;
        while (l + 1 < r)
        {
            m = (r - l) / 2 + l;
            if (nums[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return l + 1;
    }

    int maximumCount(vector<int> &nums)
    {
        // int f0 = lower_bound(nums, 0);
        // int f00 = lower_bound(nums, 1);
        // int pos = nums.size() - f00;
        // int neg = f0 - 0;
        // cout << pos << ' ' << neg;
        // return max(pos, neg);
        // 是新游戏哦
        int f0 = ranges::lower_bound(nums, 0) - nums.begin();
        int f00 = nums.end() - ranges::lower_bound(nums, 1);
        return max(f0, f00);
    }
};