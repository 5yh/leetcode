class Solution
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            int tmp = 0;
            for (int num : nums)
            {
                tmp += num >> i & 1;
            }
            if (tmp >= k)
            {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};