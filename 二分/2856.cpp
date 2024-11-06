class Solution
{
public:
    int minLengthAfterRemovals(vector<int> &nums)
    {
        // 分情况讨论，最多出现的那个数是否大于一半
        // 大于一半剩下  maxcnt*2-n n-(n-maxcnt)*2
        // 小于等于一半
        // 偶数0 奇数1
        // 如果大于一半，则nums[n/2]一定是他
        // 用二分查找第一次和最后一次出现的位置
        // upperbound大于，lowerbound大于等于
        int n = nums.size();
        int nmid = nums[n / 2];
        int first = lower_bound(nums.begin(), nums.end(), nmid) - nums.begin();
        int endd = upper_bound(nums.begin(), nums.end(), nmid) - nums.begin();
        int len = endd - first;
        // cout << len;
        if (len * 2 > n)
        {
            return len * 2 - n;
        }
        if (!(n % 2))
        {
            return 0;
        }
        return 1;
    }
};