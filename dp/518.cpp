class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
// https://leetcode.cn/problems/coin-change-ii/solutions/143948/ling-qian-dui-huan-iihe-pa-lou-ti-wen-ti-dao-di-yo/?envType=daily-question&envId=2024-03-25