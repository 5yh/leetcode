class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        int begin1 = 0;
        int i = 0;
        int cnt = 0;
        int x = (begin1 + k) % len;
        int tmp = 0;
        do
        {
            int next = (i + k) % len;
            swap(nums[next], nums[i]);

        } while (begin1 != i || cnt < len)
    }
};