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
    int search(vector<int> &nums, int target)
    {
        int ans = lower_bound(nums, target);
        if (ans == nums.size())
        {
            return -1;
        }
        if (nums[ans] != target)
        {
            return -1;
        }
        return ans;
    }
};