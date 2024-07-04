class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = nums[0];
        int r = nums[k - 1];
        int cha = nums[k - 1] - nums[0];
        int minn = cha;
        for (int i = k; i < nums.size(); i++)
        {
            cha = nums[i] - nums[i - k + 1];
            if (cha < minn)
            {
                minn = cha;
            }
        }
        return minn;
    }
};