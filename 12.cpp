class Solution
{
public:
    string chan(int num)
    {
        string re = "";
        if (num == 0)
        {
            re = "";
        }
        else if (num >= 1 && num <= 3)
        {
            while (num != 0)
            {
                re += 'I';
                num--;
            }
        }
        else if (num == 4)
        {
            re = "IV";
        }
        else if (num == 5)
        {
            re = "V";
        }
        else if (num >= 6 && num < 9)
        {
            re += "V";
            while (num != 5)
            {
                re += 'I';
                num--;
            }
        }
        else if (num == 9)
        {
            re = "IX";
        }
        else if (num >= 10 && num <= 30)
        {
            while (num != 0)
            {
                re += 'X';
                num -= 10;
            }
        }
        else if (num == 40)
        {
            re = "XL";
        }
        else if (num == 50)
        {
            re = "L";
        }
        else if (num >= 60 && num < 90)
        {
            re += "L";
            while (num != 50)
            {
                re += 'X';
                num -= 10;
            }
        }
        else if (num == 90)
        {
            re = "XC";
        }
        else if (num >= 100 && num <= 300)
        {
            while (num != 0)
            {
                re += 'C';
                num -= 100;
            }
        }
        else if (num == 400)
        {
            re = "CD";
        }
        else if (num == 500)
        {
            re = "D";
        }
        else if (num >= 600 && num < 900)
        {
            re += "D";
            while (num != 500)
            {
                re += 'C';
                num -= 100;
            }
        }
        else if (num == 900)
        {
            re = "CM";
        }
        else if (num >= 1000 && num <= 3000)
        {
            while (num != 0)
            {
                re += 'M';
                num -= 1000;
            }
        }
        return re;
    }
    string intToRoman(int num)
    {
        int qian = (num - num % 1000);               // 3000
        int bai = (num - qian) - (num - qian) % 100; // 700
        int shi = (num - qian - bai) - (num - qian - bai) % 10;
        int ge = num % 10;
        // std::cout << chan(qian) << endl
        //           << chan(bai) << endl
        //           << chan(shi) << endl
        //           << chan(ge) << endl;
        // return "";
        return chan(qian) + chan(bai) + chan(shi) + chan(ge);
    }
};