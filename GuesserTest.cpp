/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};



TEST(GuesserTest, constructor_test_one)
{
  Guesser pass("Secret");
  ASSERT_TRUE(pass.match("Secret"));
}

TEST(GuesserTest, constructor_test_two)
{
  Guesser pass("yya");
  ASSERT_TRUE(pass.match("yya"));
}

TEST(GuesserTest, constructor_test_three)
{
  Guesser pass("");
  ASSERT_TRUE(pass.match(""));
}

TEST(GuesserTest, constructor_test_four)
{
  Guesser pass("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
  ASSERT_TRUE(pass.match("abcdefghijklmnopqrstuvwxyzabcdef"));
}

TEST(GuesserTest, constructor_test_five)
{
  Guesser pass("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
  ASSERT_TRUE(pass.match("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEF"));
}

TEST(GuesserTest, constructor_test_six)
{
  Guesser pass("#@*^!@");
  ASSERT_TRUE(pass.match("#@*^!@"));
}

TEST(GuesserTest, constructor_test_seven)
{
  Guesser pass("@#$$#@#@#@$#@$#@%$Y&^%$#$R#$#$$%&*(*&^%$#%!#@!@)");
  ASSERT_TRUE(pass.match("@#$$#@#@#@$#@$#@%$Y&^%$#$R#$#$$%"));
}

TEST(GuesserTest, constructor_test_eight)
{
  Guesser pass("j@#$$#@#@#@$#@$#@%$Y&^%$#$R#$#$$%&*(*&^%$#%!#@!@)rte");
  ASSERT_FALSE(pass.match("j@#$$#@#@#@$#@$#@%$Y&^%$#$R#$#$$%&*(*&^%$#%!#@!@)rte"));
}

TEST(GuesserTest, match_trial_one)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("2E1&A*"));
}

TEST(GuesserTest, match_trial_two)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("2E1&a**"));
}

TEST(GuesserTest, match_trial_three)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("2E1&a"));
}

TEST(GuesserTest, match_trial_four)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("What"));
}

TEST(GuesserTest, match_trial_five)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("2E1&A**"));
}

TEST(GuesserTest, match_trial_six)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("2E18a"));
}

TEST(GuesserTest, match_trial_seven)
{
  Guesser pass("2E1&a*");
  ASSERT_FALSE(pass.match("2E18a*ebdacan"));
}

TEST(GuesserTest, match_trial_eight)
{
  Guesser pass("2E1&a*");
  pass.match("2E18a*ebdacan");
  ASSERT_FALSE(pass.match("2E1&a*"));
}

TEST(GuesserTest, match_trial_nine)
{
  Guesser pass("2E1&a*");
  pass.match("#@3312zebdacan");
  ASSERT_FALSE(pass.match("2E1&a*"));
}

TEST(GuesserTest, lock_trial_one)
{
  Guesser pass("2E1&a*");
  pass.match("2E1&a");
  pass.match("2E1&a");
  pass.match("2E1&a");
  ASSERT_FALSE(pass.match("2E1&a*"));
}

TEST(GuesserTest, lock_trial_two)
{
  Guesser pass("2E1&a*");
  pass.match("2E1&a");
  pass.match("2E1&a");
  ASSERT_TRUE(pass.match("2E1&a*"));
}

TEST(GuesserTest, lock_trial_three)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  pass.match("2E2&a");
  ASSERT_TRUE(pass.match("2E1&a*"));
}

TEST(GuesserTest, lock_trial_four)
{
  Guesser pass("2E1&a*");
  pass.match("2E1&a");
  pass.match("2E1&a");
  pass.match("2E1&a*");
  pass.match("2E1&a");
  ASSERT_TRUE(pass.match("2E1&a*"));
}

TEST(GuesserTest, lock_trial_five)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  pass.match("2E2&a");
  pass.match("2E1&a*");
  pass.match("2E2&a");
  ASSERT_TRUE(pass.match("2E1&a*"));
}

TEST(GuesserTest, lock_trial_six)
{
  Guesser pass("2E1&a*");
  pass.match("2m2&a");
  ASSERT_FALSE(pass.match("2E1&a*"));
}

TEST(GuesserTest, remainder_trial_one)
{
  Guesser pass("2E1&a*");
  ASSERT_EQ(pass.remaining(), 3);
}

TEST(GuesserTest, remainder_trial_two)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  ASSERT_EQ(pass.remaining(), 2);
}

TEST(GuesserTest, remainder_trial_three)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  pass.match("2E2&a");
  ASSERT_EQ(pass.remaining(), 1);
}

TEST(GuesserTest, remainder_trial_four)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  pass.match("2E2&a");
  pass.match("2E2&a");
  ASSERT_EQ(pass.remaining(), 0);
}

TEST(GuesserTest, remainder_trial_five)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  pass.match("2E2&a");
  pass.match("2E1&a*");
  ASSERT_EQ(pass.remaining(), 3);
}

TEST(GuesserTest, remainder_trial_six)
{
  Guesser pass("2E1&a*");
  pass.match("2E2&a");
  pass.match("2E1&a*");
  pass.match("2E2&a");
  ASSERT_EQ(pass.remaining(), 2);
}

TEST(GuesserTest, remainder_trial_seven)
{
  Guesser pass("2E1&a*");
  pass.match("aaaa");
  pass.match("aaaa");
  ASSERT_EQ(pass.remaining(), 1);
}

TEST(GuesserTest, remainder_trial_eight)
{
  Guesser pass("2E1&a*");
  pass.match("aaaa");
  ASSERT_EQ(pass.remaining(), 2);
}

TEST(GuesserTest, remainder_trial_nine)
{
  Guesser pass("2E1&a*");
  pass.match("aaaa");
  pass.match("aaaa");
  pass.match("aaaa");
  ASSERT_EQ(pass.remaining(), 0);
}

