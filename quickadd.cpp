auto quickAdd = [](int y, int z, int x)
{
    // x,y是负数，z是正数
    // 判断y*z是否小于x
    int result = 0, add = y;
    while (z)
    {
        if (z % 2 == 1)
        {
            // result+add<x result和add两个负数可能溢出，改为负数加一个正数 一定不溢出
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