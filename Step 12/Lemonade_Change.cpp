class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for(int i = 0; i < n; i++)
        {
            if(bills[i] == 5)
                five++;
            else if(bills[i] == 10)
            {
                five--;
                ten++;
            }
            else if(ten > 0)
            {
                ten--;
                five--;
            }
            else
                five = five - 3;
            if(five < 0)
                return false;
        }
        return true;
        
    }
};