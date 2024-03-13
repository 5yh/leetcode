class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int count[32];
        for (auto num : nums)
        {
            for (int j = 0; j < 32; j++)
            {
                count[j] += num & 1;
                num >>= 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            // 为什么先左移一位
            ans <<= 1;
            ans |= count[31 - i] % 3;
        }
        return ans;
    }
};