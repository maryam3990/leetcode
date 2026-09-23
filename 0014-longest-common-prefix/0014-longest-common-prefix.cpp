class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int n = strs.size();
        string s = strs[0];

        for(int i = 1; i<n; i++)
        { 
            int k = 0;
            string ans = "";
            for(int j = 0; strs[i][j]!='\0' && s[k]!='\0'; j++)
            {
                if(s[k] == strs[i][j])
                { 
                    ans+=strs[i][j];
                    ++k;
                }
                else break;
            }
            s = ans;
            if(s=="") return s;
        }
        return s;
    }
};