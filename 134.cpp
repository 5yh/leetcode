class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int len = gas.size();
        for (int i = 0; i < len; i++)
        {
            if (gas[i] < cost[i])
            {
                continue;
            }
            else
            {
                int gass = gas[i];
                int j = 1;
                for (; j <= len; j++)
                {
                    // cout << gass << ' ' << cost[(i + j - 1) % len] << ' ' << gas[(i + j) % len] << endl;
                    if (gass - cost[(i + j - 1) % len] < 0)
                    {
                        break;
                    }
                    gass = gass - cost[(i + j - 1) % len] + gas[(i + j) % len];
                    // cout << gass << endl;
                }
                if (j > len)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};