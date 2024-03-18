class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int count=1;
        sort(points.begin(),points.end());
        int n=points.size();
        int start=points[0][0];
        int end=points[0][1];
        int i=1;

        while(i<n)
        {
            if (start<=points[i][0] and points[i][0]<=end)
            {
                start=points[i][0];
                end=min(end,points[i][1]);
            }
            else
            {
                count++;
                start=points[i][0];
                end=points[i][1];
            }
            i++;
        }
        return count;
    }
};