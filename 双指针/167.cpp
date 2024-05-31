class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int len = numbers.size();
        int left = 0;
        int right = len - 1;
        while (numbers[left] + numbers[right] != target)
        {
            if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
        }
        vector<int> ans(2);
        ans[0] = left + 1;
        ans[1] = right + 1;
        return ans;
    }
};