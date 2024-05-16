class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int k = 0;
        for (int i = 0; i < len; i++)
        {
            if (k < i)
                return false;
            k = max(k, nums[i] + i);
        }
        return true;
    }
};