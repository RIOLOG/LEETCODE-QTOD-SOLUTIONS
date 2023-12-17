class FoodRatings
{
public:
    unordered_map<string, vector<string>> mp;
    unordered_map<string, int> ratingMap;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &rating)
    {
        for (int i = 0; i < cuisines.size(); i++)
        {
            mp[cuisines[i]].push_back(foods[i]);
        }

        for (int i = 0; i < foods.size(); i++)
        {
            ratingMap[foods[i]] = rating[i];
        }
    }

    void changeRating(string food, int newRating)
    {
        auto it = ratingMap.find(food);
        if (it != ratingMap.end())
        {
            ratingMap.erase(it);
        }
        ratingMap[food] = newRating;
    }

    string highestRated(string cuisine)
    {
        string ans = "";
        int priority = -1;

        auto x = mp.find(cuisine);
        if (x != mp.end())
        {
            for (auto y : x->second)
            {
                auto rate = ratingMap.find(y);
                if (rate != ratingMap.end() and rate->second > priority)
                {
                    priority = rate->second;
                    ans = y;
                }
                else if (rate != ratingMap.end() and rate->second == priority and y < ans)
                    ans = y;
            }
        }
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */