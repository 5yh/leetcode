class Solution
{
public:
    // 只要是写两个判断函数的，都时间很长
    // 其实一次判断函数即可
    bool manzu2(vector<int> &bloomDay, int m, int k, int mday, int i)
    {
        for (int j = i; j < i + k; j++)
        {
            if (bloomDay[j] > mday)
            {
                return false;
            }
        }
        return true;
    }
    bool manzu(vector<int> &bloomDay, int m, int k, int mday)
    {
        int cnt = 0;
        int i = 0;
        while (i <= bloomDay.size() - k)
        {
            // cout << "a";
            if (bloomDay[i] > mday)
            {
                i++;
                continue;
            }
            if (manzu2(bloomDay, m, k, mday, i))
            {
                // cout << "i" << i << '\n';
                i += k;

                cnt++;
                // cout << cnt << endl;
            }
            else
            {
                // cout << "c";
                i++;
            }
        }
        // cout << mday << ' ';
        // cout << cnt << endl;
        if (cnt >= m)
        {
            return true;
        }
        return false;
    }
    // bool canMake(vector<int> &bloomDay, int days, int m, int k)
    // {
    //     int bouquets = 0;
    //     int flowers = 0;
    //     int length = bloomDay.size();
    //     for (int i = 0; i < length && bouquets < m; i++)
    //     {
    //         if (bloomDay[i] <= days)
    //         {
    //             flowers++;
    //             if (flowers == k)
    //             {
    //                 bouquets++;
    //                 flowers = 0;
    //             }
    //         }
    //         else
    //         {
    //             flowers = 0;
    //         }
    //     }
    //     return bouquets >= m;
    // }
    bool canmake2(vector<int> &bloomDay, int m, int k, int mday)
    {
        int flower = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mday)
            {
                flower++;
                if (flower >= k)
                {
                    cnt++;
                    flower = 0;
                }
            }
            else
            {
                flower = 0;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // long long
        if ((long long)bloomDay.size() < (long long)m * (long long)k)
        {
            return -1;
        }
        auto [min_d, max_d] = ranges::minmax(bloomDay);
        int l = min_d - 1;
        int r = max_d + 1;
        while (l + 1 < r)
        {
            int mid = (r - l) / 2 + l;
            if (canmake2(bloomDay, m, k, mid))
            // if (manzu(bloomDay, m, k, mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
};