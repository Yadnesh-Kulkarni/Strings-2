//Time complexity : O(m+n)
//Space complexity : O(n)
class Solution {
public:
    int m;
    int n;
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        
        m = haystack.size();
        n = needle.size();
        
        vector<int> lsp = getLSP(needle);
        
        int i = 0;
        int j = 0;
        
        while(i < m)
        {   
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
                if(j == n)
                {
                    return i - n;
                }
            }
            else if(haystack[i] != needle[j] && j > 0)
            {
                j = lsp[j - 1];
            }
            else if(haystack[i] != needle[j] && j == 0)
            {
                i++;
            }
        }
        
        return -1;
    }
    
    vector<int> getLSP(string str)
    {
        int j = 0;
        int i = 1;
        vector<int> lsp(str.size(), 0);
        while(i < n)
        {
            //1. If Characters are equal
            if(str[i] == str[j])
            {
                j++;
                lsp[i] = j;
                i++;
            }
            //2. If Characters are not equal and j > 0
            else if(str[i] != str[j] && j > 0)
            {
                j = lsp[j - 1];    
            }
            
            //3. If characters are not equal and j == 0
            else if(str[i] != str[j] && j == 0)
            {
                lsp[i] = 0;
                i++;
            }
        }
        
        return lsp;
    }
};