class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_set<int> set1;
        unordered_map<int, int> map1;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            map1[fruits[r]]++;
            while (map1.size() > 2)
            {
                map1[fruits[l]]--;
                if (map1[fruits[l]] == 0)
                {
                    map1.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};