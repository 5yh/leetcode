class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int chen = k * threshold;
        int summ = 0;
        int cntt = 0;
        for (int i = 0; i < k; i++)
        {
            summ += arr[i];
        }
        if (summ >= chen)
        {
            cntt++;
        }
        for (int i = k; i < arr.size(); i++)
        {
            summ -= arr[i - k];
            summ += arr[i];
            if (summ >= chen)
            {
                cntt++;
            }
        }
        return cntt;
    }
};