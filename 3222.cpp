class Solution
{
public:
    string losingPlayer(int x, int y)
    {
        bool isAlice = true;
        while (1)
        {
            if (x >= 1)
            {
                if (y >= 4)
                {
                    x--;
                    y -= 4;
                    isAlice = !isAlice;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (isAlice)
        {
            return "Bob";
        }
        else
        {
            return "Alice";
        }
    }
};