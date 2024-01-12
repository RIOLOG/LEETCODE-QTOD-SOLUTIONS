class Solution {
bool isVowel(char x)
{
    return (x == 'a' or x == 'A' or x == 'e' or x == 'E' or x == 'i' or x == 'I' or x == 'o' or x == 'O' or x == 'u' or x == 'U');
}
public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int count1 = 0 , count2 = 0;
        int i = 0 , j = n / 2;
        
        while(i < n/2 and j < n)
        {
            if(isVowel(s[i]))   count1 += 1;
            if(isVowel(s[j]))   count2 += 1;
            i += 1;
            j += 1;
        }
        
        return (count1 == count2);
    }
};