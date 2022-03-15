class Solution
{
public:
    string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void findCombinations(string digits, string currentCombination,
                          int index, vector<string> &result)
    {
        if (index == digits.length())
        {
            result.push_back(currentCombination);
            return;
        }

        string temp = keypad[digits[index] - '0'];

        for (int i = 0; i < temp.length(); i++)
        {
            findCombinations(digits, currentCombination + temp[i], index + 1, result);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.length() == 0)
            return result;

        findCombinations(digits, "", 0, result);
        return result;
    }
};