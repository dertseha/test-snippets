#pragma once

#include <chrono>

namespace publicdomain::testsnippets::system {

/**
 * \link Time \endlink provides an abstraction of the current date/time. The
 * values provided by this interface may be affected by changes in the system,
 * such as user intervention or time-synchronization.
 */
class Time {
public:
  virtual ~Time() = default;

  /**
   * @return the current date/time, in nanoseconds since unix epoch.
   */
  virtual std::chrono::nanoseconds now() = 0;
};

} // namespace publicdomain::testsnippets::system
