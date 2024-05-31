class Solution
{
public:
    // 写不出来
    string longestPalindrome(string s)
    {
        int n = s.size();
        int anslen = 0;
        int ansbegin = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i;
            int right = n - 1;
            int juli = right - left + 1;
            cout << "left" << left << endl;
            cout << "right" << right << endl;
            cout << "juli" << juli << endl;
            while (left <= right)
            {
                if (s[left] == s[right])
                {
                    left++;
                    right--;
                    cout << "while if left" << left << endl;
                    cout << "while if right" << right << endl;
                }
                else
                {
                    right--;
                    juli = right - left + 1;
                    cout << "while else right" << right << endl;
                }
            }
            if (left > right)
            {
                cout << "left>right" << endl;
                anslen = anslen > juli ? anslen : juli;
                if (anslen < juli)
                {
                    anslen = juli;
                    ansbegin = i;
                    cout << "anslen" << anslen << ' ' << "ansbegin" << ansbegin << endl;
                }
            }
        }
        cout << ansbegin << endl;
        cout << anslen << endl;
        return s.substr(ansbegin, anslen);
    }
};