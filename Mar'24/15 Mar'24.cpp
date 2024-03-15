class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // brute-force:
        //  int n = nums.size();
        //  vector<int>ans(n);
        //  for (int i=0;i<n;i++)
        //  {
        //      int cals = 1 ;
        //      for (int j=0;j<n;j++)
        //      {
        //          if (i != j)   cals *= nums[j];
        //      }
        //      ans[i] = cals;
        //  }
        //  return ans;

        // method-2:
        int n = nums.size();
        int zero = 0;
        int product = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero += 1;
            else
                product *= nums[i];
        }

        vector<int> ans(n, 0);
        if (zero >= 2)
            return ans;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                ans[i] = product;
            else
            {
                if (zero == 1)
                    ans[i] = 0;
                else
                    ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};