class Solution
{
public:
    bool manzu(vector<int> &heights, vector<int> &cha, int bricks, int ladders, int mid)
    {
        // 对前mid进行排序

        std::vector<int> newVec(cha.begin(), cha.begin() + mid + 1);
        sort(newVec.begin(), newVec.begin() + mid + 1, std::greater<int>());
        // for (int i = 0; i < newVec.size(); i++)
        // {
        //     cout << newVec[i] << ' ';
        // }
        // cout << endl;
        int i = 0;
        while (i < ladders)
        {
            i++;
        }
        int cntbrick = 0;
        while (i <= mid)
        {
            cntbrick += newVec[i];
            i++;
        }
        // cout << "cntbrickk" << cntbrick << endl;
        if (cntbrick > bricks)
        {
            return false;
        }
        return true;
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        vector<int> cha(n + 1);
        for (int i = 1; i < n; i++)
        {
            // 直接嗯排序
            cha[i] = (heights[i] - heights[i - 1]) > 0 ? (heights[i] - heights[i - 1]) : 0;
        }
        int l = 0;
        int r = n;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            // cout << "mid:" << m << endl;
            if (manzu(heights, cha, bricks, ladders, m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};