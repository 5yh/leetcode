class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j >= 1; j--)
            {
                f[j] = min(f[j], f[j - 1]) + triangle[i][j];
            }
            f[0] = f[0] + triangle[i][0];
        }

        int minn = 999999999;
        for (int i = 0; i < n; i++)
        {
            minn = minn > f[i] ? f[i] : minn;
        }
        return minn;
    }
};