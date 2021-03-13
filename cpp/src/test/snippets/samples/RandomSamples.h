#pragma once

#include <string>

namespace publicdomain::testsnippets::samples::random {

/**
 * @return a random name for a person
 */
std::string aRandomName();

/**
 * @return a random given name of a person
 */
std::string someGivenName();

/**
 * @param limit the size of the array to index
 * @return a random number between 0 (inclusive) and limit (exclusive)
 */
size_t aRandomIndexFor(size_t limit);

/**
 * @return a random 64bit number
 */
int64_t aRandomNumber();

} // namespace publicdomain::testsnippets::samples::random
