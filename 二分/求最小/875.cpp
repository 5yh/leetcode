class Solution
{
public:
    bool manzu(vector<int> &piles, int h, int speed)
    {
        // cout << speed << ' ';
        long long cnth = 0;
        int i = 0;
        while (i < piles.size())
        {
            if (piles[i] <= speed)
            {
                cnth++;
                i++;
            }
            else
            {
                // cnth += piles[i] / speed;
                // cnth += (piles[i] + speed - 1) / speed;
                cnth += (long long)((piles[i] - 1) / speed + 1);
                i++;
            }
        }
        // cout << cnth << endl;
        if (cnth <= h)
        {
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // l取1
        // r取max
        int l = 0;
        int r = ranges::max(piles) + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(piles, h, m))
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