// Approach 1:

class Solution
{
public:
    void helper(string str, int k, string &maxVal)
    {
        if (k == 0)
            return;

        int n = str.length();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (str[i] < str[j])
                {
                    swap(str[i], str[j]);
                    if (str.compare(maxVal) > 0)
                    {
                        maxVal = str;
                    }
                    helper(str, k - 1, maxVal);
                    swap(str[i], str[j]);
                }
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string maxVal = str;
        helper(str, k, maxVal);
        return maxVal;
    }
};

// Approach 2:

class Solution
{
public:
    void helper(string str, int index, int k, string &maxVal)
    {
        if (k == 0)
            return;

        int n = str.length();
        char currMax = str[index];
        for (int i = index + 1; i < n; i++)
        {
            if (str[i] > currMax)
            {
                currMax = str[i];
            }
        }

        if (str[index] != currMax)
        {
            k--;
        }

        for (int i = index; i < n; i++)
        {
            if (str[i] == currMax)
            {
                swap(str[index], str[i]);
                if (str.compare(maxVal) > 0)
                {
                    maxVal = str;
                }
                helper(str, index + 1, k, maxVal);
                swap(str[index], str[i]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string maxVal = str;
        helper(str, 0, k, maxVal);
        return maxVal;
    }
};