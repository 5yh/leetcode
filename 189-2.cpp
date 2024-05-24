class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        vector<int> kk(k);
        for (int i = 0; i < k; i++)
        {
            kk[i] = nums[len - k + i];
        }
        for (int i = 0; i < len - k; i++)
        {
            nums[i] = nums[(len - k + i) % len];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = kk[i];
        }
    }
};