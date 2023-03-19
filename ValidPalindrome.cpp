//
// Created by ザスキ・オスカー on 2023/03/19.
//

#include <gtest/gtest.h>

using namespace std;

bool isPalindrome(string s) {
    string t;
    for (const char& c : s) {
        if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
            t += c;
        } else if (c >= 'A' && c <= 'Z') {
            t += c + 32;
        }
    }
    s = t;
    std::reverse(t.begin(), t.end());
    return s == t;
}

TEST(ValidPalindrome, Case1) {
    ASSERT_EQ(true, isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(ValidPalindrome, Case2) {
    ASSERT_EQ(false, isPalindrome("race a car"));
}

TEST(ValidPalindrome, Case3) {
    ASSERT_EQ(true, isPalindrome(" "));
}


TEST(ValidPalindrome, Case4) {
    ASSERT_EQ(false, isPalindrome("0P"));
}
