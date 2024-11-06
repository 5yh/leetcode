class Solution
{
public:
    bool manzu(int n, int k, int budget, vector<vector<int>> &composition, vector<int> stock, vector<int> &cost, int m, int ki)
    {
        long long cost1 = 0;
        for (int j = 0; j < n; j++)
        {
            // cout << "n:" << n << "k:" << k << "budget:" << budget << "m" << m << "ki:" << ki << "j:" << j << endl;
            if ((long long)composition[ki][j] * m > (long long)stock[j])
                cost1 += (long long)((long long)composition[ki][j] * m - (long long)stock[j]) * cost[j];
        }
        // cout << "cost1" << cost1 << endl;
        if (cost1 == 0)
        {
            return true;
        }
        if (cost1 <= budget)
        {
            return true;
        }
        // cout << "false" << endl;
        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        int maxx = 0;
        for (int i = 0; i < k; i++)
        {
            int l = -1;
            int r = 1000000000;
            while (l + 1 < r)
            {
                int m = (r - l) / 2 + l;
                if (manzu(n, k, budget, composition, stock, cost, m, i))
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            maxx = max(l, maxx);
        }
        return maxx;
    }
};