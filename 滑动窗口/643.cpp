class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int summ = 0;
        int maxx = 0;
        for (int i = 0; i < k; i++)
        {
            summ += nums[i];
        }
        maxx = summ;
        for (int i = k; i < nums.size(); i++)
        {
            summ -= nums[i - k];
            summ += nums[i];
            if (summ > maxx)
            {
                maxx = summ;
            }
        }
        return (double)maxx / (double)k;
    }
};