class Solution {
public:
    bool isodd(int n)
    {
        if (n % 2 != 0)  return true;
        return false;
    }
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        int count = 0;
        for (int i=0;i<arr.size();i++)
        {
            if (isodd(arr[i]))
            {
                count += 1;
                if (count == 3)  return true;
            }
            else
            {
                count = 0;
            }
        }
        return false;
    }
};