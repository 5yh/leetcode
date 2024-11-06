class Solution
{
public:
    // 两次二分太慢了
    // 第二次不用二分
    // bool manzu2(long long rank, int cars, long long costtime, long long carss)
    // {
    //     if (carss * carss * rank <= costtime)
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    // bool manzu(vector<int> &ranks, int cars, long long costtime)
    // {
    //     // cout << "costtime" << costtime << ' ';
    //     // 要看在costtime里一共能修几辆车
    //     long long cnt = 0;
    //     for (int i = 0; i < ranks.size(); i++)
    //     {
    //         // cout << "now i" << i << endl;
    //         long long l = 1 - 1;
    //         long long r = cars + 1;
    //         long long ans = 0;
    //         // 用修的车辆数来做二分
    //         while (l + 1 < r)
    //         {
    //             long long m = (r - l) / 2 + l;
    //             // cout << "BBB\n";

    //             if (manzu2(ranks[i], cars, costtime, m))
    //             {
    //                 // cout << ranks[i] << ' ' << cars << ' ' << costtime << ' ' << m << endl;
    //                 // cout << "aaaaaaaa\n";
    //                 // cout << m << endl;
    //                 l = m;
    //                 ans = m;
    //             }
    //             else
    //             {
    //                 r = m;
    //             }
    //         }
    //         // cout << "now add ans" << ans << endl;
    //         cnt += ans;
    //     }
    //     // cout << "cnt" << cnt << endl;
    //     if (cnt >= cars)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    // 可以直接开根
    bool manzu3(vector<int> &ranks, int cars, long long aaa)
    {
        long long s = 0;
        for (int r : ranks)
        {
            s += sqrt(aaa / r);
        }
        if (s >= cars)
        {
            return true;
        }
        return false;
    }

    long long repairCars(vector<int> &ranks, int cars)
    {
        long long l = 0;
        long long maxx = ranges::min(ranks);
        long long r = (long long)maxx * (long long)cars * (long long)cars;
        // cout << l << ' ' << r;
        while (l + 1 < r)
        {
            long long m = (r - l) / 2 + l;
            if (manzu3(ranks, cars, m))
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return r;
    }
};