class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        vector<int> maxor(nums.size());
        vector<int> ans(nums.size());
        maxor[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            maxor[i] = maxor[i + 1] | nums[i];
        }
        for (int i = 0; i < maxor.size(); i++)
        {
            int ansi = 0;
            int tmpor = 0;
            while (tmpor != maxor[i])
            {
                tmpor |= nums[i + ansi];
                ansi++;
            }
            if (ansi == 0)
                ansi++;
            ans[i] = ansi;
        }
        return ans;
    }
};