#include <gtest/gtest.h>

bool substringPatternIsRepeated(std::string s) {
    bool match;
    for (size_t substr_size = 1; substr_size < (s.size() / 2) + 1; substr_size++) {
        if ((s.size() % substr_size) == 0) {
            // potential beginning of new substr
            match = true;
            for (size_t index = 0; match && index < substr_size; index++) {
                for (size_t substr_front = substr_size; match && substr_front < s.size(); substr_front += substr_size) {
                    if (s[substr_front + index] != s[index]) {
                        match = false;
                    }
                }
            }
            if (match) {
                return true;
            }
        }
    }

    return false;
}

TEST(repeated_substring, repeated_substring_length_2_twice) {
    ASSERT_TRUE(substringPatternIsRepeated("abab"));
}

TEST(repeated_substring, not_repeated_substring_length_2_twice) {
    ASSERT_FALSE(substringPatternIsRepeated("aba"));
}

TEST(repeated_substring, repeated_substring_length_3_or_length_6) {
    ASSERT_TRUE(substringPatternIsRepeated("abcabcabcabc"));
}

TEST(repeated_substring, not_repeated_substring_length_3_or_length_6) {
    ASSERT_FALSE(substringPatternIsRepeated("abcababcabc"));
}

TEST(repeated_substring, repeated_substring_length_1_odd) {
    ASSERT_TRUE(substringPatternIsRepeated("zzzzzzz"));
}

TEST(repeated_substring, repeated_substring_length_1_even) {
    ASSERT_TRUE(substringPatternIsRepeated("zzzzzzzz"));
}

TEST(repeated_substring, not_repeated_single_char) {
    ASSERT_FALSE(substringPatternIsRepeated("z"));
}

TEST(repeated_substring, partially_repeated_substring) {
    ASSERT_FALSE(substringPatternIsRepeated("abababcb"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
