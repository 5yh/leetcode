class Solution
{
public:
    bool manzu(vector<int> &dist, double hour, int speed)
    {
        double summ = 0;
        for (int i = 0; i < dist.size() - 1; i++)
        {
            summ += (double)((dist[i] - 1) / speed + 1);
        }
        summ += (double)(dist[dist.size() - 1]) / (double)(speed);
        if (summ <= hour)
        {
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int len = dist.size();
        if ((double)(len - 1) >= hour)
        {
            return -1;
        }
        // l为1，r为多少

        int maxs = 0;
        // double shengyuhour=
        maxs = INT_MAX - 100000000;
        int l = 0;
        int r = maxs + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(dist, hour, m))
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