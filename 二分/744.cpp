class Solution
{
public:
    int lower_bound(vector<char> &letters, char target)
    {
        int l = -1;
        int r = letters.size();
        int m = 0;
        while (l + 1 < r)
        {
            m = (r - l) / 2 + l;
            if (letters[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return l + 1;
    }
    char nextGreatestLetter(vector<char> &letters, char target)
    {

        int ans = lower_bound(letters, target + 1);
        cout << ans;
        if (ans == letters.size())
        {
            return letters[0];
        }
        return letters[ans];
    }
};