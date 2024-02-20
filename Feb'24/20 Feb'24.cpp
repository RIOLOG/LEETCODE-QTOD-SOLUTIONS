class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        //math
        // int n = nums.size();
        // int total_sum = (n * (n+1)) / 2;
        // int sum = 0;
        // for (int i=0;i<n;i++)   sum += nums[i];
        // return total_sum - sum;
        
        
        //sorting:
        sort(nums.begin(), nums.end());
        int num = 0;
        for (int i=0;i<nums.size();i++)
        {
            if (num == nums[i])   num += 1;
            else                  return num;
        }
        return num ;
        
        
        
        
        
        //repeat and missing:
       // int n = arr.size();
//         int totalSum = (n * (n+1)) / 2;
//         int sum = 0;
//         for (int i=0;i<n;i++)   sum += arr[i];
        
//         sort(arr.begin(), arr.end());
//         int repeat = -1;
//         for (int i=0;i<n-1;i++)
//         {
//             if (arr[i] == arr[i+1])
//             {
//                 repeat = arr[i];
//                 break;
//             }
//         }
        
//         if (totalSum < sum)
//         {
//             int diff = sum - totalSum;
//             return (repeat - diff);
//         }

//         int diff = sum - totalSum;
//         return (repeat + diff);
        
        
//         ans.push_back(repeat);
//         reverse(ans.begin(), ans.end());
//         return ans;
    }
};