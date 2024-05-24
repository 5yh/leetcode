class Solution
{
public:
    void reverse(vector<int> &nums, int begin1, int end1)
    {
        while (begin1 < end1)
        {
            swap(nums[begin1++], nums[end1--]);
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k % len - 1);
        reverse(nums, k % len, len - 1);
    }
};