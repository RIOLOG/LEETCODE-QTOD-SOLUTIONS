class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        int n = arr.size();
        int req = n * (0.25);
        
        for (int i=0;i<n-req;i++)
        {
            if (arr[i] == arr[i+req])   return arr[i];
        }
        
        return -1;
    }
};