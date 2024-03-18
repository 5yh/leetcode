// bit[i]=bit[i>>1]+(i&1)
class Solution
{
public:
    int numbits(int num)
    {
        int ans = 0;
        while (num)
        {
            num &= num - 1;
            ans++;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        // 值传递方式lambda=
        sort(arr.begin(), arr.end(), [=](int a, int b)
             {
            if(numbits(a)==numbits(b)){
                return a<b;
            }else{
                return numbits(a)<numbits(b);
            } });
        return arr;
    }
};