// class Solution {
// public:
//     bool canArrange(vector<int>& nums, int k)
//     {
//         int n = nums.size();
//         if (n % 2 != 0)   return false;
//         int count = 0;
        
//         unordered_map<int, int>mp;
//         for (int i=0;i<nums.size();i++)   mp[nums[i]]++;
        
//         // cout<<"INITIALSS"<<endl;
//         // for (auto x:mp)   cout<<x.first<<" "<<x.second<<endl;
//         // cout<<"INITIALSS SIZEEEE"<<" "<<mp.size()<<endl;
        
//         for (auto x: mp)
//         {
//             if (x.second % 2 == 1)   x.second = 1;
//         }
        
//         for(int i=0;i<nums.size();i++)
//         {
//             int num = nums[i];
//             if (!mp[num])   continue;
            
//             if (mp.size() == 0)   break;
                
//             for (auto x: mp)
//             {
//                 int need = x.first;
                
//                 if (need == num and mp[need] <= 1)   continue;
                
//                 else if (mp[num] <= 0 or mp[need] <= 0)  continue;
                
//                 else if ((need + num) % k == 0)
//                 {
//                     //cout<<"INSIDEEE"<<endl;
//                     //cout<<"num"<<" "<<num<<" "<<"need"<<" "<<need<<endl;
                    
//                     // mp.erase(need);
//                     // mp.erase(num);
//                     // break;
//                     count += 1;
//                     mp[need] -= 1;
//                     if (mp[need] == 0)   mp.erase(need);
//                     mp[num] -= 1;
//                     if (mp[num] == 0)   mp.erase(num);
//                     //cout<<"COUNTTT"<<" "<<count<<endl;
                    
//                     break;
//                 }
//             }
//             // for (auto x:mp)   cout<<x.first<<" "<<x.second<<endl;
//             // cout<<"MID SIZEEEE"<<" "<<mp.size()<<endl;
//             if(count == nums.size() / 2)   return true;
//         }
        
//         // cout<<"FINALLSS"<<endl;
//         // for (auto x:mp)   cout<<x.first<<" "<<x.second<<endl;
        
//         return (mp.size() == 0);
//     }
// };




class Solution {
public:
    bool canArrange(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (n % 2 != 0)   return false;
        
        unordered_map<int, int>mp;
        for (auto x: nums)  
        {
            int rem = (x % k + k) % k;    //Handling negative elements:
            mp[rem] += 1;
        }
        
        if (mp[0] % 2 != 0)   return false;
        
//         for (auto x: nums)
//         {
//             int curr = (x % k + k) % k;
//             int req = k - curr;
            
//             if (mp.find(req) != mp.end())
//             {
//                 mp.erase(req);
//                 mp.erase(curr);
//             }
//         }
        
        for (int i=1;i<=k/2;i++)
        {
            int curr = i;
            int rem = k - curr;
            if (mp[curr] != mp[rem])   return false;
        }
        
        return true;
    }
};