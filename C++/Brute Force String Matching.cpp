#include <iostream>
#include <string>

void bruteForceStringMatch(std::string text, std::string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            std::cout << "Pattern found at index " << i << std::endl;
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    bruteForceStringMatch(text, pattern);
    return 0;
}
