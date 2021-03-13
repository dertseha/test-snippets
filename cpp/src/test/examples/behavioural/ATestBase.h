#pragma once

#include <gmock/gmock.h>

#include "snippets/behavioural/Steps.h"
#include "snippets/fixtures/SimulatedTimeFixture.h"

namespace publicdomain::testsnippets::examples {

/**
 * \link ATestBase \endlink is an example how a \link
 * publicdomain::testsnippets::behavioural::Steps \endlink-based test framework
 * with common fixtures could be set up.
 *
 * Having an abstract class with all the fixtures is not always necessary,
 * single tests could implement \link
 * publicdomain::testsnippets::behavioural::Steps \endlink directly. Integration
 * tests are primary examples of candidates that need (most of) the surrounding
 * fixtures of a system under test.
 *
 * As a recommendation, fixtures should represent collaborators on the external
 * interfaces of the system/component.
 *
 * @tparam SubType The test type deriving from this class.
 */
template <typename SubType>
class ATestBase
    : public testing::Test,
      public publicdomain::testsnippets::behavioural::Steps<SubType> {
public:
  /**
   * @return the fixture for time
   */
  publicdomain::testsnippets::fixtures::SimulatedTimeFixture &time() {
    return timeFixture;
  }

private:
  publicdomain::testsnippets::fixtures::SimulatedTimeFixture timeFixture;
};

} // namespace publicdomain::testsnippets::examples
