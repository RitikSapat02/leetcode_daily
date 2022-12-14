class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, string> mp;
        vector<string> vc;
        set<string> st;
        istringstream ss(s);
        string word;
        while (ss >> word)
        {
            vc.push_back(word);
            st.insert(word);
        }
        if (pattern.length() != vc.size())
            return false;
        for (int i = 0; i < pattern.length(); i++)
        {
            if (mp.find(pattern[i]) != mp.end())
            {
                if (mp[pattern[i]] != vc[i])
                    return false;
            }
            else
                mp[pattern[i]] = vc[i];
        }
        if (st.size() != mp.size())
            return false;
        return true;
    }
};