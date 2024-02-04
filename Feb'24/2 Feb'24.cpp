class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        string check = "123456789";

        for (int i = 0; i < check.size(); i++)
        {
            string Totry = "";

            for (int j = i; j < check.size(); j++)
            {
                Totry += (check[j]);
                int number = stoi(Totry);

                if (number >= low and number <= high)
                    ans.push_back(number);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};