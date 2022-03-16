// Approach : Stack based

class Solution
{
public:
    int getRemovalCount(string str)
    {
        stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (s.size() > 0 && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(str[i]);
                }
            }
        }
        return s.size();
    }

    void helper(string str, int removalCount, vector<string> &result, unordered_map<string, int> &mp)
    {
        if (mp[str] != 0)
            return;

        mp[str]++;
        if (removalCount == 0)
        {
            if (getRemovalCount(str) == 0)
            {
                result.push_back(str);
            }
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            string prefix = str.substr(0, i);
            string suffix = str.substr(i + 1);
            helper(prefix + suffix, removalCount - 1, result, mp);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> result;
        unordered_map<string, int> mp;
        int removalCount = getRemovalCount(s);
        helper(s, removalCount, result, mp);
        return result;
    }
};