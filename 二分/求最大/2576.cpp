class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        ranges::sort(nums);
        unordered_map<int, int> numbiaoji;
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int l = -1;
            int r = i;
            while (l + 1 < r)
            {
                int m = (r - l) / 2 + l;
                if (nums[m] * 2 <= nums[i])
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            if (numbiaoji[l])
            {
                continue;
            }
            cout << "i" << i << "l" << l << endl;
            if (l >= 0)
            {
                numbiaoji[i]++;
                numbiaoji[l]++;
                cnt++;
                cnt++;
            }
        }
        return cnt;
    }
};