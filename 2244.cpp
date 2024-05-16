class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> cnt;
        for (auto num : tasks)
        {
            cnt[num]++;
        }
        int ans = 0;
        for (auto &[k, v] : cnt)
        {
            if (v % 3 == 0)
            {
                ans += v / 3;
            }
            else if (v == 1)
            {
                ans = -1;
                break;
            }
            else if ((v - 1) % 3 == 0)
            {
                ans += (v - 1) / 3 - 1;
                ans += 2;
            }
            else if ((v + 1) % 3 == 0)
            {
                ans += (v + 1) / 3;
            }
        }
        return ans;
    }
};