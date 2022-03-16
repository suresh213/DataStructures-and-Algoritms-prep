class Solution
{
public:
    bool isPalindrome(string str)
    {
        int len = str.length();
        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    void helper(string str, vector<string> currentPartition,
                vector<vector<string>> &result)
    {
        if (str.length() == 0)
        {
            result.push_back(currentPartition);
            return;
        }
        for (int i = 0; i < str.length(); i++)
        {
            string prefix = str.substr(0, i + 1);
            string suffix = str.substr(i + 1);

            if (isPalindrome(prefix))
            {
                currentPartition.push_back(prefix);
                helper(suffix, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        helper(s, {}, result);
        return result;
    }
};

class Solution
{
public:
    bool isPalindrome(string str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }

    void part(string str, int index, vector<string> currentPartition,
              vector<vector<string>> &result)
    {
        if (index == str.length())
        {
            result.push_back(currentPartition);
            return;
        }
        for (int i = index; i < str.length(); i++)
        {
            if (isPalindrome(str, index, i))
            {
                currentPartition.push_back(str.substr(index, i - index + 1));
                part(str, i + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        part(s, 0, {}, result);
        return result;
    }
};