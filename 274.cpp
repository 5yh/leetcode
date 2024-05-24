class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int len = citations.size();
        sort(citations.begin(), citations.end());
        int h = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (citations[i] > h)
            {
                h++;
            }
        }
        return h;
    }
};