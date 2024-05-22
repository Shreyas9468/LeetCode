#include <vector>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string &str, int i, int j) {
        while (i <= j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void dfs(std::vector<std::vector<std::string>> &result, std::vector<std::string> &ans, int index, const std::string &s) {
        if (index == s.length()) {
            result.push_back(ans);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                ans.push_back(s.substr(index, i - index + 1));
                dfs(result, ans, i + 1, s);
                ans.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(const std::string &s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> ans;
        dfs(result, ans, 0, s);
        return result;
    }
};
