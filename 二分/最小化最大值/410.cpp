

class Solution
{
public:
    bool manzu(vector<int> &inventory, int orders, int m)
    {
        int subsum = 0;
        int maxx = 0;
        int cntgeshu = 0;
        int n = inventory.size();
        for (int i = 0; i < n; i++)
        {
            if (subsum + inventory[i] <= m)
            {
                // cout << inventory[i] << "add in\n";
                subsum += inventory[i];
                maxx = max(maxx, subsum);
            }
            else
            {
                // cout << "manle\n";
                subsum = inventory[i];
                cntgeshu++;
            }
        }
        cntgeshu++;
        // cout << "cnt个数：" << cntgeshu << endl;
        // cout << "orders:" << orders << endl;
        if (cntgeshu <= orders)
        {
            return true;
        }
        return false;
    }
    int splitArray(vector<int> &nums, int k)
    {
        // auto [min_d, max_d] = ranges::minmax(inventory);
        int maxx = 0;
        int summ = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            summ += nums[i];
            maxx = max(maxx, nums[i]);
        }
        int l = maxx - 1;
        int r = summ + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            // cout << "k" << k << ' ' << "m" << m << endl;
            if (manzu(nums, k, m))
            {

                r = m;
            }
            else
            {
                l = m;
            }
        }
        return r;
    }
};