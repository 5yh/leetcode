class Solution
{
public:
    bool manzu(vector<int> &weights, int days, int shipweight)
    {
        // cout << "aaa" << shipweight << endl;
        int cntday = 1;
        int zaizhong = 0;
        int i = 0;
        while (i < weights.size())
        {
            if (zaizhong + weights[i] <= shipweight)
            {
                zaizhong += weights[i];

                // cout << weights[i] << ' ';
                i++;
            }
            else
            {
                // cout << zaizhong << endl;
                zaizhong = 0;
                cntday++;
                // cout << endl;
            }
        }
        if (cntday <= days)
        {
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        // 二分船的重量
        // min是最大单个货物
        // max先用sum
        int l = ranges::max(weights) - 1;
        int r = std::accumulate(weights.begin(), weights.end(), 0) + 1;
        int ans = 0;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(weights, days, m))
            {
                r = m;
                ans = m;
            }
            else
            {
                l = m;
            }
        }
        return ans;
    }
};