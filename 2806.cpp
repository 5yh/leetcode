class Solution
{
public:
    int accountBalanceAfterPurchase(int purchaseAmount)
    {
        int xiao = purchaseAmount / 10;
        int da = xiao + 1;
        int xiao10 = xiao * 10;
        int da10 = xiao10 + 10;
        if ((purchaseAmount - xiao10) < (da10 - purchaseAmount))
        {
            return 100 - xiao10;
        }
        else
        {
            return (100 - da10);
        }
    }
};