#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::AtLeast;

struct Turtle {
  virtual ~Turtle() {}
  virtual void Turn(int degrees) = 0;
};

struct MockTurtle : Turtle {
  MOCK_METHOD(void, Turn, (int degrees), (override));
};

// INFO: From Compiling googlemock/src/gmock-spec-builders.cc:
// external/com_google_googletest/googlemock/src/gmock-spec-builders.cc:437:14:
// warning: no previous declaration for 'testing::internal::CallReaction
// testing::internal::intToCallReaction(int)' [-Wmissing-declarations]
//   438 | CallReaction intToCallReaction(int mock_behavior) {
//       |              ^~~~~~~~~~~~~~~~~

TEST(TurleTest, Turns) {
  MockTurtle turtle;
  EXPECT_CALL(turtle, Turn(10)).Times(AtLeast(1));
  turtle.Turn(10);
}

TEST(ExampleTest, Example) { EXPECT_TRUE(true); }

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
