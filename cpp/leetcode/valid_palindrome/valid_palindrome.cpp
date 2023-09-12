#include <gtest/gtest.h>
#include <cctype>

bool palindrome_is_valid(std::string s) {
    std::string::iterator front = s.begin();
    std::string::reverse_iterator back = s.rbegin();
    while (front != back.base() && front != back.base() - 1) {
        if (!isalnum(*back)) {
            back++;
            continue;
        }
        if (!isalnum(*front)) {
            front++;
            continue;
        }
        if (std::tolower(*front) != std::tolower(*back)) {
            return false;
        }
        front++;
        back++;
    }
    
    return true;
}

TEST(palindrome, valid_with_symbols_and_spaces_and_capitalization) {
    ASSERT_TRUE(palindrome_is_valid("A man, a plan, a canal: Panama"));
}

TEST(palindrome, invalid_with_symbols_and_spaces_and_capitalization) {
    ASSERT_FALSE(palindrome_is_valid("A man, a pla, a canal: Panama"));
}

TEST(palindrome, invalid_with_spaces) {
    ASSERT_FALSE(palindrome_is_valid("race a car"));
}

TEST(palindrome, valid_with_spaces) {
    ASSERT_TRUE(palindrome_is_valid("race car"));
}

TEST(palindrome, valid_empty_string) {
    ASSERT_TRUE(palindrome_is_valid(""));
}

TEST(palindrome, valid_only_spaces) {
    ASSERT_TRUE(palindrome_is_valid("      "));
}

TEST(palindrome, valid_even_length) {
    ASSERT_TRUE(palindrome_is_valid("abccba"));
}

TEST(palindrome, invalid_even_length) {
    ASSERT_FALSE(palindrome_is_valid("abcdba"));
}

TEST(palindrome, valid_odd_length) {
    ASSERT_TRUE(palindrome_is_valid("abcdcba"));
}


TEST(palindrome, invalid_odd_length) {
    ASSERT_FALSE(palindrome_is_valid("abcddba"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
