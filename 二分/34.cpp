class Solution
{
public:
    // 闭区间
    // 找到大于等于
    int lower_bound1(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            // int m = (l + r) / 2;
            int m = (r - l) / 2 + l;
            if (nums[m] >= target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
    // 左闭右开
    int lower_bound2(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size();
        while (l < r)
        {
            // int m = (l + r) / 2;
            int m = (r - l) / 2 + l;
            if (nums[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
    // 开区间
    int lower_bound3(vector<int> &nums, int target)
    {
        int l = -1;
        int r = nums.size();
        while (l + 1 < r)
        {
            int m = l + (r - l) / 2;
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int begin1 = lower_bound3(nums, target);
        // vector<int> aaa;
        // return aaa;
        if (begin1 >= nums.size() || nums[begin1] != target)
        {
            // aaa.push_back(-1);
            // aaa.push_back(-1);
            // return aaa;
            return {-1, -1};
        }
        else
        {
            int end1 = lower_bound3(nums, target + 1) - 1;
            return {begin1, end1};
            // aaa.push_back(begin1);
            // aaa.push_back(end1);
            // return aaa;
        }
    }
};