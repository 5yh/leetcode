class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long l = 0;
        long long r = (long long)(*max_element(time.begin(), time.end())) * (long long)(totalTrips) + 1;
        while (l + 1 < r)
        {
            long long m = (r - l) / 2 + l;
            long long cnt = 0;
            for (long long num : time)
            {
                cnt += m / num;
            }
            if (cnt >= totalTrips)
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