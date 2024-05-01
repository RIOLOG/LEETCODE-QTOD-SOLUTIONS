class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                index = i;
                break;
            }
        }
        int i = 0;
        int j = index;

        while (i <= j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        return word;
    }
};