class Solution
{
public:
    int cntp = 0, cntm = 0, cntg = 0;
    int lastp = -1, lastm = -1, lastg = -1;
    int cntzong = 0;
    void GarbageLength(vector<string> &garbage)
    {
        for (int i = 0; i < garbage.size(); i++)
        {
            cntzong += garbage[i].length();
            for (int j = 0; j < garbage[i].length(); j++)
                if (garbage[i][j] == 'P')
                {
                    lastp = i;
                }
                else if (garbage[i][j] == 'G')
                {
                    lastg = i;
                }
                else if (garbage[i][j] == 'M')
                {
                    lastm = i;
                }
        }
        // std::cout << "cntp" << cntp << ' ' << "lastp" << lastp << std::endl;
        // std::cout << "cntm" << cntm << ' ' << "lastm" << lastm << std::endl;
        // std::cout << "cntg" << cntg << ' ' << "lastg" << lastg << std::endl;
    }
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        GarbageLength(garbage);
        vector<int> travelqian(travel.size());
        travelqian[0] = travel[0];
        for (int i = 1; i < travelqian.size(); i++)
        {
            travelqian[i] += travel[i];
            travelqian[i] += travelqian[i - 1];
        }
        // for (int i = 0; i < travelqian.size(); i++)
        // {
        //     std::cout << travelqian[i] << ' ';
        // }
        int ppp = 0;
        int ggg = 0;
        int mmm = 0;
        if (lastp != -1)
        {
            if (lastp != 0)
            {
                ppp += travelqian[lastp - 1];
            }
        }
        if (lastg != -1)
        {
            if (lastg != 0)
            {
                ggg += travelqian[lastg - 1];
            }
        }
        if (lastm != -1)
        {
            if (lastm != 0)
            {
                mmm += travelqian[lastm - 1];
            }
        }
        return ppp + ggg + mmm + cntzong;
    }
};
// 先倒着看最后一个此类垃圾在哪一家
