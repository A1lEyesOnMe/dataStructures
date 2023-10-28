#include <iostream>
#include <vector>
#include <string>

void computeLPS(const std::string& pattern, std::vector<int>& lps) {
    int m = pattern.length();
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    computeLPS(pattern, lps);

    std::vector<int> matches;
    int i = 0, j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            ++j;
            ++i;
        }

        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    return matches;
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABC";

    std::vector<int> result = KMP(text, pattern);

    if (!result.empty()) {
        std::cout << "Pattern found at positions:";
        for (int pos : result) {
            std::cout << " " << pos;
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }

    return 0;
}
