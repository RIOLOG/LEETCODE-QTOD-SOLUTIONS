class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        // sorting:
        sort(prices.begin(), prices.end());
        int req = prices[0] + prices[1];

        if (req > money)
            return money;
        return money - req;
    }
};