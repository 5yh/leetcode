auto quickAdd = [](int y, int z, int x)
{
    // y*z大于x返回true
    // xy小于0，z大于0
    int result = 0;
    int add = y;
    while (z)
    {
        if (z % 2 == 1)
        {
            if (result < x - add)
            {
                return false;
            }
            result += add;
        }
        if (z != 1)
        {
            if (add < x - add)
            {
                return false;
            }
            add += add;
        }
        z >>= 1;
    }
    return true;
};