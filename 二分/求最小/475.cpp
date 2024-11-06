class Solution
{
public:
    // bool manzu(vector<int> &houses, vector<int> &heaters, int radius)
    // {
    //     // cout << radius << ' ';
    //     unordered_map<int, int> aaa;
    //     for (int i = 0; i < heaters.size(); i++)
    //     {
    //         for (int j = 0; j <= radius; j++)
    //         {
    //             // if (heaters[i] - radius >= 1)
    //             // {
    //             aaa[heaters[i] - j]++;
    //             // }
    //             // if (heaters[i] + radius <= houses.back())
    //             // {
    //             aaa[heaters[i] + j]++;
    //             // }
    //         }
    //     }
    //     // for (auto aaa1 : aaa)
    //     // {
    //     //     cout << "aaa";
    //     //     cout << aaa1.first << ' ';
    //     //     cout << aaa1.second << endl;
    //     // }

    //     for (int i = 0; i < houses.size(); i++)
    //     {
    //         if (aaa[houses[i]] == 0)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    bool manzu(vector<int> &houses, vector<int> &heaters, int radius)
    {
        int n = houses.size();
        int m = heaters.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < m && heaters[j] + radius < houses[i])
            {
                j++;
            }
            if (j < m && heaters[j] + radius >= houses[i] && heaters[j] - radius <= houses[i])
                continue;
            return false;
        }
        return true;
    }
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        ranges::sort(houses);
        ranges::sort(heaters);

        int l = -1;
        int r = max(houses.back(), heaters.back());
        int ans = 0;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(houses, heaters, m))
            {
                r = m;
                ans = m;
                // cout << "aaaaaaaaaa";
            }
            else
            {
                l = m;
            }
        }
        return ans;
    }
};