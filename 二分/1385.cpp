class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        // 找第一个大于等于x的和第一个小于x的
        // 第一个大于等于的左边就是第一个小于的
        for (auto &x : arr1)
        {
            int p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size())
            {
                ok &= (arr2[p] - x > d);
            }
            if (p - 1 >= 0 && p - 1 < arr2.size())
            {
                ok &= (x - arr2[p - 1] > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};