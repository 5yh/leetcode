class Solution
{
public:
    // 爆了
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        // 不可行，success是long long
        // vector<double> potions2(potions.size());
        // for (int i = 0; i < potions.size(); i++)
        // {
        //     potions2[i] = double(potions[i]);
        // }
        vector<int> pairs(spells.size());
        for (int i = 0; i < spells.size(); i++)
        {
            // 这里要乘一下

            int pos = lower_bound(potions2.begin(), potions2.end(), )
        }
    }
};