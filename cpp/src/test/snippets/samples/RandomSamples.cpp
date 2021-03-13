#include <random>

#include "snippets/samples/RandomSamples.h"

using namespace publicdomain::testsnippets::samples::random;

std::string publicdomain::testsnippets::samples::random::aRandomName() {
  return someGivenName() + " Doe";
}

std::string publicdomain::testsnippets::samples::random::someGivenName() {
  static std::vector<std::string> names{"Alice", "Bob", "Carol", "David"};
  return names[aRandomIndexFor(names.size())];
}

size_t
publicdomain::testsnippets::samples::random::aRandomIndexFor(size_t limit) {
  return static_cast<size_t>(aRandomNumber()) % limit;
}

int64_t publicdomain::testsnippets::samples::random::aRandomNumber() {
  // The default engine may not provide a full range of values for a 64bit
  // integer, so build one up using 16bit values.
  static std::random_device device;
  static std::default_random_engine engine(device());
  static std::uniform_int_distribution<uint16_t> distribution(0x0000, 0xFFFF);

  return static_cast<int64_t>(
      (static_cast<uint64_t>(distribution(engine)) << 48ULL) |
      (static_cast<uint64_t>(distribution(engine)) << 32ULL) |
      (static_cast<uint64_t>(distribution(engine)) << 16ULL) |
      (static_cast<uint64_t>(distribution(engine)) << 0ULL));
}
