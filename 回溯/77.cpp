class Solution
{
public:
    // void dfs()
    // 有一种方法不用数1的个数，直接计算出下一个二进制
    // 每一次都计算太慢了
    // https://leetcode.cn/problems/combinations/solutions/405094/zu-he-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        // 1-n中k个数的组合
        int cishu = (1 << n);
        for (int i = 0; i < cishu; i++)
        {
            vector<int> tmpans;
            if (__builtin_popcount(i) == k)
            {
                int tmpi = i;
                for (int j = 0; j < 32; j++)
                {
                    if (i & (1 << j))
                    {
                        tmpans.push_back(j + 1);
                    }
                }
            }
            if (!tmpans.empty())
                ans.push_back(tmpans);
        }
        return ans;
    }
};