class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        int juli = 'a' - 'A';
        while (i <= j)
        {
            if (!(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9'))
            {
                i++;
                continue;
            }
            if (!(s[j] >= 'A' && s[j] <= 'Z') && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= '0' && s[j] <= '9'))
            {
                j--;
                continue;
            }
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += juli;
            }
            if (s[j] >= 'A' && s[j] <= 'Z')
            {
                s[j] += juli;
            }
            if (s[i] == s[j])
            {
                i++;
                j--;
                // cout<<s[i]<<' '<<s[j]<<endl;
            }
            else
            {
                break;
            }
        }
        if (i <= j)
        {
            return false;
        }
        return true;
    }
};