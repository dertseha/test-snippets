#include "snippets/system/SystemTime.h"

using namespace publicdomain::testsnippets::system;

std::chrono::nanoseconds SystemTime::now() {
  return std::chrono::system_clock::now().time_since_epoch();
}
