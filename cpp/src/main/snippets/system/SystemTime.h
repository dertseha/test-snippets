#pragma once

#include "Time.h"

namespace publicdomain::testsnippets::system {

/**
 * \link SystemTime \endlink provides date/time values from the system.
 */
class SystemTime : public publicdomain::testsnippets::system::Time {
public:
  std::chrono::nanoseconds now() override;
};

} // namespace publicdomain::testsnippets::system
