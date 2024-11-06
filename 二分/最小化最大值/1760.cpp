class Solution
{
public:
    bool manzu(vector<int> &nums, int maxOperations, int mid)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 不能整除要少一次
            if (nums[i] % mid == 0)
            {
                cnt += nums[i] / mid - 1;
            }
            else
            {
                cnt += nums[i] / mid;
            }
        }
        // cout << cnt << endl;
        if (cnt <= maxOperations)
        {
            return true;
        }
        return false;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 0;
        int r = ranges::max(nums) + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            // cout << "mo" << maxOperations << ' ' << "m" << m << endl;
            if (manzu(nums, maxOperations, m))
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return r;
    }
};