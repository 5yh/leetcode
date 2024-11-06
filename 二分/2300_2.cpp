class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int cnt = 0;
        // 上界不好除，要改成下界，这样直接除没有问题，每次二分只要做一次除法
        // 直接用原数组
        sort(potions.begin(), potions.end());
        for (int &x : spells)
        {
            long long target = (success - 1) / x;
            if (target < potions.back())
            {
                // 其实大于直接用upper_bound也可以
                x = potions.end() - lower_bound(potions.begin(), potions.end(), (int)target + 1);
            }
            else
            {
                x = 0;
            }
        }
        return spells;
    }
};