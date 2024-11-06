class Solution
{
public:
    bool manzu(int mountainHeight, vector<int> &workerTimes, long long time1)
    {
        long long cnt = 0;
        for (auto worktime : workerTimes)
        {
            cnt += (sqrt((long long)time1 / worktime * 8 + 1) - 1) / 2;
        }
        if (cnt >= mountainHeight)
        {
            return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        // 时间单调，可以二分
        long long minn = ranges::min(workerTimes);
        long long maxx = ranges::max(workerTimes);
        long long r = (1 + (long long)mountainHeight) * (long long)mountainHeight / (long long)2 * (long long)maxx + (long long)1;
        long long l = 0;
        cout << r << endl;
        while (l + 1 < r)
        {
            long long m = (r - l) / 2 + l;
            cout << m;
            if (manzu((long long)mountainHeight, workerTimes, m))
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