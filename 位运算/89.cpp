class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int cc = 1;
            for (int j = ans.size() - 1; j >= 0; j--)
            {
                ans.push_back(cc + ans[j]);
            }
            cc <<= 1;
        }
        return ans;
    }
};