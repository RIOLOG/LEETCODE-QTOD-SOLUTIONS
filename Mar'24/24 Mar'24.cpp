class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // NAIVE:
        //  sort(nums.begin(),nums.end());
        //  for (int i=0;i<nums.size()-1;i++)
        //  {
        //      if (nums[i] == nums[i+1])   return nums[i];
        //  }
        //  return 0;

        // HASHMAP:
        //  unordered_map<int,int>mp;
        //  for (auto x:nums)
        //  {
        //      if (!mp[x])
        //      {
        //          mp[x]++;
        //      }
        //      else
        //      {
        //          return x;
        //      }
        //  }
        //  return 0;

        // OPTMAL: (FAST AND SLOW POINTER):
        //         int slow = nums[0];
        //         int fast = nums[0];

        //         do
        //         {
        //             slow = nums[slow];
        //             fast = nums[nums[fast]];
        //         }while(fast != slow);

        //         fast = nums[0];
        //         // slow = nums[0];
        //         while(fast != slow)
        //         {
        //             slow = nums[slow];
        //             fast = nums[fast];
        //         }

        //         return slow;

        //....making index negatives:...//
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]);
            if (nums[index] < 0)
                return index;

            nums[index] = -nums[index];
        }

        return 0;
    }
};