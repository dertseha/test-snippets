#pragma once

#include "snippets/system/Time.h"

namespace publicdomain::testsnippets::system {

/**
 * \link SimulatedTime \endlink is used instead of \link SystemTime \endlink to
 * allow tests to control the passage of time.
 *
 * The start value is an arbitrary value.
 */
class SimulatedTime : public publicdomain::testsnippets::system::Time {
public:
  SimulatedTime() : value(NoonOnFirstDayOfYear2000) {}
  ~SimulatedTime() override = default;

  std::chrono::nanoseconds now() override { return value; }

  /**
   * Set changes the current time to the given value. This is for cases a test
   * needs a specific date/time.
   *
   * @param newValue the new value for now
   */
  void set(std::chrono::nanoseconds const &newValue) { value = newValue; }

  /**
   * Pass adds the given duration to the current value of now.
   *
   * @param duration how much time shall be added to the current value.
   *        This value can be a negative duration.
   */
  template <class Rep, class Period = std::ratio<1>>
  void pass(std::chrono::duration<Rep, Period> const &duration) {
    value += std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
  }

private:
  uint64_t const NoonOnFirstDayOfYear2000 = 1577876400000000000ULL;

  std::chrono::nanoseconds value;
};

} // namespace publicdomain::testsnippets::system
