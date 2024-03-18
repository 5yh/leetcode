class Solution
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        vector<int> wei(32);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; nums[i]; j++)
            {
                wei[j] += (nums[i] & 1);
                nums[i] >>= 1;
            }
        }
        // for (int i = 0; i < 32; i++)
        // {
        //     cout << wei[i] << endl;
        // }
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            ans <<= 1;
            if (wei[i] >= k)
            {
                // cout << "i" << i << endl;
                ans += 1;
            }
        }
        return ans;
    }
};