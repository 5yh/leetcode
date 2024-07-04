class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int cntt = 0;
        int len = customers.size();
        for (int i = 0; i < len; i++)
        {
            if (grumpy[i] == 0)
            {
                cntt += customers[i];
            }
        }
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i] == 1)
            {
                cntt += customers[i];
            }
        }
        for (int i = 1; i + minutes - 1 < len; i++)
        {
            if (grumpy[i - 1] == '1')
            {
                cntt -= customers[i - 1];
            }
            if (grumpy[i + minutes - 1] == '1')
            {
                cntt += customers[i + 1];
            }
        }
    }
};