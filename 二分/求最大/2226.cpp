class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        // 不用求和sum，直接令ans=0，如果总和小于人数的话ans还是0
        int l = 0;
        int r = *max_element(candies.begin(), candies.end()) + 1;
        int n = candies.size();
        int ans = 0;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            long long cnt = 0;
            for (int i = 0; i < n; i++)
            {
                cnt += (long long)(candies[i] / m);
            }
            if (cnt >= k)
            {
                l = m;
                ans = m;
            }
            else
            {
                r = m;
            }
        }
        return ans;
    }
};