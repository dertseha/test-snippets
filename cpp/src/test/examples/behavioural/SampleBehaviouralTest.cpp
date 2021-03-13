#include "ATestBase.h"

namespace publicdomain::testsnippets::examples {

/**
 * \link SampleBehaviouralTest \endlink shows a possible usage of
 * \link ATestBase \endlink.
 */
class SampleBehaviouralTest : public ATestBase<SampleBehaviouralTest> {
public:
  /**
   * This method is an example for a test-specific step.
   */
  void specialCaseShouldBeFulfilled() { EXPECT_TRUE(true); }
};

/**
 * This test case is an example on how steps would be used.
 */
TEST_F(SampleBehaviouralTest, demonstrationOfSteps) {
  when().time().passes(std::chrono::hours(20));
  then().specialCaseShouldBeFulfilled();
}

} // namespace publicdomain::testsnippets::examples
