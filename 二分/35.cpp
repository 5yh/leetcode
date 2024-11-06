class Solution
{
public:
    // 闭区间
    int lower_bound(vector<int> &nums, int target)
    {
        int l = -1;
        int r = nums.size();
        int m;
        while (l + 1 < r)
        {
            // m = (l + r) / 2;
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
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums, target);
    }
};