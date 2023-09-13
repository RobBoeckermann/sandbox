#include <gtest/gtest.h>

// Q: can we jump in both directions, or only to the right?
// A: it doesn't matter, because, if jumping to the left would lead us to last index, we could have jumped there on the way to the right instead of jumping over it.

// I see two approaches:
//  A) use DFS to trace each possible jump until the last index is reached or we run out of possible places to jump.
//  B) search for all 0s, the only value that can stop out movement to the right, and check whether any indexes to the left will allow jumping over the 0.
//
// Approach A is more computationally intensive, because it is essentially a brute-force approach that requires "playing out" all possible jumps looking for a success.
// Since the conditions for potentially "blocking" a possible jump to the last index are so easy to identify (the presence of a 0), it is more efficient, in this case, to search for assured failures instead of guarunteed successes.


bool canJump(std::vector<int> &nums)
{
    bool jumpable;
    if (nums.size() == 1) {
        return true;
    }
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == 0)
        {
            jumpable = false;
            for (int j = i - 1, diff = 1; j >= 0; j--, diff++)
            {
                if (nums[j] > diff)
                {
                    jumpable = true;
                    break;
                }
            }
            if (!jumpable)
            {
                return false;
            }
        }
    }
    return true;
}

TEST(jump_game, success_no_zeros) {
    std::vector<int> test = {2,3,1,1,4};
    ASSERT_TRUE(canJump(test));
}

TEST(jump_game, failure_impassible_zero) {
    std::vector<int> test = {3,2,1,0,4};
    ASSERT_FALSE(canJump(test));
}

TEST(jump_game, success_passible_zero)
{
    std::vector<int> test = {5, 3, 2, 1, 0, 4};
    ASSERT_TRUE(canJump(test));
}

TEST(jump_game, success_single_index0)
{
    std::vector<int> test = {0};
    ASSERT_TRUE(canJump(test));
}

TEST(jump_game, success_single_index1)
{
    std::vector<int> test = {1};
    ASSERT_TRUE(canJump(test));
}

TEST(jump_game, failure_starting_zero)
{
    std::vector<int> test = {0,1,2,3};
    ASSERT_FALSE(canJump(test));
}

TEST(jump_game, success_jump_to_end)
{
    std::vector<int> test = {2,0,0};
    ASSERT_TRUE(canJump(test));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
