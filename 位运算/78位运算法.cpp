class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // 子集个数就是2的n次方，用数字位表示
        int shuzi = nums.size();
        int maxx = 1 << shuzi;
        for (int i = 0; i < maxx; i++)
        {
            vector<int> tmpv;
            int tmpi = i;
            for (int j = 0; j < 32; j++)
            {
                if (tmpi & 1)
                {
                    tmpv.push_back(nums[j]);
                }
                tmpi >>= 1;
            }

            ans.push_back(tmpv);
        }
        // ans.push_back(vector<int>());
        return ans;
    }
};