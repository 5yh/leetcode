class Solution
{
public:
    // 只要找到一个在区间范围内的数，就代表不符合
    // 如果arr2中存在一个数 y 且满足 num−d≤y≤num+d，那么arr1中的数x就不满足题目要求。
    bool binarySearch(vector<int> &arr, int low, int high)
    {
        int l = -1;
        int r = arr.size();
        int m = 0;
        while (l + 1 < r)
        {
            m = (r - l) / 2 + l;
            if (arr[m] >= low && arr[m] <= high)
            {
                return true;
            }
            else if (arr[m] < low)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return false;
    }
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int cnt = 0;
        sort(arr2.begin(), arr2.end());
        for (auto &x : arr1)
        {
            int low = x - d;
            int high = x + d;
            if (!binarySearch(arr2, low, high))
            {
                cnt++;
            }
        }
        return cnt;
    }
};