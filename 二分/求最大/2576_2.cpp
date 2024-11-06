class Solution
{
public:
    bool manzu(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            if (nums[n - k + i] < nums[i] * 2)
            {
                return false;
            }
        }
        return true;
    }
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        ranges::sort(nums);
        int l = -1;
        int n = nums.size();
        int r = n / 2 + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(nums, m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l * 2;
    }
};