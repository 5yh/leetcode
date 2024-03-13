// 位运算，数组
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> uset;
        for (auto &num : nums)
        {
            uset[num]++;
        }
        for (auto &num : nums)
        {
            if (uset[num] == 1)
                return num;
        }
        return 0;
    }
};