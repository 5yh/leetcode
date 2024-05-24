class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        vector<int> baocun(len);
        for (int i = 0; i < len; i++)
        {
            baocun[(i + k) % len] = nums[i];
        }
        for (int i = 0; i < len; i++)
        {
            nums[i] = baocun[i];
        }
    }
};