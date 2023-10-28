#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int ALPHABET_SIZE = 256;

// 计算坏字符规则
void badCharHeuristic(const std::string& pattern, std::vector<int>& badChar) {
    int m = pattern.length();

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        badChar[i] = -1;
    }

    for (int i = 0; i < m; ++i) {
        badChar[static_cast<int>(pattern[i])] = i;
    }
}

// 计算好后缀规则
void goodSuffixHeuristic(const std::string& pattern, std::vector<int>& goodSuffix) {
    int m = pattern.length();
    std::vector<int> suff(m);

    // 计算后缀数组suff
    for (int i = m - 2; i >= 0; --i) {
        int j = i;
        while (j >= 0 && pattern[j] == pattern[m - 1 - i + j]) {
            --j;
        }
        suff[i] = i - j;
    }

    // Case 1
    for (int i = 0; i < m; ++i) {
        goodSuffix[i] = m;
    }

    // Case 2
    int j = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (suff[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (goodSuffix[j] == m) {
                    goodSuffix[j] = m - 1 - i;
                }
            }
        }
    }

    // Case 3
    for (int i = 0; i <= m - 2; ++i) {
        goodSuffix[m - 1 - suff[i]] = m - 1 - i;
    }
}

// Boyer-Moore算法
std::vector<int> boyerMoore(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> badChar(ALPHABET_SIZE, 0);
    std::vector<int> goodSuffix(m, 0);
    std::vector<int> matches;

    badCharHeuristic(pattern, badChar);
    goodSuffixHeuristic(pattern, goodSuffix);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[i + j]) {
            --j;
        }

        if (j < 0) { // 匹配成功
            matches.push_back(i);
            i += (i + m < n) ? m - badChar[text[i + m]] : 1;
        } else {
            i += std::max(goodSuffix[j], j - badChar[text[i + j]]);
        }
    }

    return matches;
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABC";

    std::vector<int> result = boyerMoore(text, pattern);

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
