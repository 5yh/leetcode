class Solution
{
    // g了
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            int aa = 0;
            if (!(i % 2))
            {
                aa = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            }
            else
            {
                aa = lower_bound(arr.begin(), arr.end(), x + 1) - arr.begin() - 1;
            }
            cout << aa << arr[aa] << endl;
            ans.push_back(arr[aa]);
            arr.erase(arr.begin() + aa);
        }
        return ans;
    }
};