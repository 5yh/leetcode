class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> cishu(len, INT_MAX);
        cishu[0] = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j <= nums[i] && i + j < len; j++)
            {
                cishu[i + j] = min(cishu[i + j], cishu[i] + 1);
                if (i + j == len - 1)
                {
                    return cishu[i + j];
                }
            }
        }
        return cishu[len - 1];
    }
};