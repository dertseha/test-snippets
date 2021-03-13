#pragma once

#include "snippets/system/SimulatedTime.h"

namespace publicdomain::testsnippets::fixtures {

/**
 * \link SimulatedTimeFixture \endlink handles an instance of \link
 * publicdomain::testsnippets::system::SimulatedTime \endlink as a test fixture.
 *
 * Depending on how the system under test receives the reference to the \link
 * publicdomain::testsnippets::system::Time \endlink, the fixture could provide
 * a getter to retrieve the instance, and the test could inject it.
 */
class SimulatedTimeFixture {
public:
  /**
   * A When step for passing time.
   *
   * @tparam Rep template parameter for duration
   * @tparam Period template parameter for duration
   * @param duration how much time shall be added to the current value.
   *        This value can be a negative duration.
   */
  template <class Rep, class Period = std::ratio<1>>
  void passes(std::chrono::duration<Rep, Period> const &duration) {
    time.pass(duration);
  }

private:
  publicdomain::testsnippets::system::SimulatedTime time;
};

} // namespace publicdomain::testsnippets::fixtures