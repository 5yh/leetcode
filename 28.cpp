class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack; i++)
        {
            int s = i;
            int b = 0;
            if (s + needle.size() > haystack.size())
            {
                return -1;
            }
            while (b < needle.size())
            {
                if (haystack[s] != needle[b])
                {
                    break;
                }
            }
            if (b < needle.size())
            {
                continue;
            }
            else
            {
                return i;
            }
        }
        return -1;
    }
};