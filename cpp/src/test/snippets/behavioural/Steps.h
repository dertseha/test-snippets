#pragma once

namespace publicdomain::testsnippets::behavioural {

/**
 * \link Steps \endlink provides a standard set of starting words for test
 * steps. These are based on the <a
 * href="https://en.wikipedia.org/wiki/Behavior-driven_development#Behavioral_specifications">behavioural
 * specifications</a>, used in Behaviour-driven development (BDD). Note that
 * using this does NOT make your tests BDD-tests. There is far more to BDD than
 * using the three steps of Given-When-Then.
 *
 * The intention of this is to provide a handrail for writing tests.
 * Tests are typically written in an Arrange-Act-Assert manner, and instead of
 * using these clunky names, more appropriate words are used to start a
 * human-readable sentence.
 *
 * See also the article '<a href="https://dannorth.net/whats-in-a-story/">What's
 * in a story?</a>' by Dan North.
 *
 * The interface uses recursive generics pattern to allow the step methods
 * provide access to possible extension methods in the implementing test.
 *
 * The following is an example for tests that use dedicated fixtures for
 * collaborators.
 * @code
 * template <typename SubType>
 * class ATestBase
 *   : public testing::Test,
 *     public publicdomain::testsnippets::behavioural::Steps<SubType> {
 *     // ...
 *     Server server() {
 *         return serverFixture;
 *     }
 *     // ...
 * };
 *
 * class ExampleTest: public ATestBase<ExampleTest> {
 * };
 *
 * TEST_F(ExampleTest, example) {
 *     given().server().knowsUser();
 *     when().client().logsIn();
 *     then().database().shouldHaveActiveUserCountOf(1);
 * }
 * @endcode
 *
 * @tparam SubType The test type deriving from this interface.
 */
template <class SubType> class Steps {
public:
  virtual ~Steps() = default;

  /**
   * Given steps are those setting up the system/instance under test. They
   * arrange for the actual act to happen. These steps may contain assertions
   * within them, to ensure a proper setup. These assertions should not be used
   * as actual test evidence, as corresponding assertions should exist in
   * dedicated tests.
   *
   * Tests can have any number of steps, from zero to several. The ideal number
   * is one. Given steps should be the first ones of a test, followed by a
   * When step.
   *
   * Given steps should be named using past tense or state facts.
   * They indicate preconditions for the act.
   *
   * Examples:
   * @code
   * given().configuration().enablesLoggingLevelDebug();
   * given().server().knowsUser();
   * given().client().loggedIn();
   * @endcode
   *
   * @return a reference to this, cast as SubType.
   */
  SubType &given() { return asSubType(); }

  /**
   * When steps are those performing the act that triggers the test subject for
   * the action that is being tested.
   *
   * Tests should have exactly one When step that follows all Given steps.
   * If the test fails, the action of this When step should be the one to be
   * investigated.
   *
   * When steps should be named in present verb form. They indicate the action
   * the test observes.
   *
   * Examples:
   * @code
   * when().client().logsIn();
   * when().messageSystem().deliversMessage();
   * when().server().closesConnections();
   * @endcode
   *
   * @return a reference to this, cast as SubType.
   */
  SubType &when() { return asSubType(); }

  /**
   * Then steps perform the assertions. They verify that certain conditions are
   * reached.
   *
   * Tests should have exactly one Then step. This depends on the assertion
   * library used and the approach how assertions are treated: Should a test
   * report all non-matched conditions, or abort at the first failed assertion.
   *
   * Then steps should be named with a conditional. If a test breaks, it may be
   * that the assumptions of the test no longer match and they may need
   * adaption. For a more detailed reasoning, see <a
   * href="https://dannorth.net/introducing-bdd/">Introducing BDD</a> by Dan
   * North.
   *
   * Examples:
   * @code
   * then().database().shouldHaveActiveUserCountOf(1);
   * then().client().shouldReceiveAnErrorResponse();
   * then().server().shouldHaveAPendingLogInRequest();
   * @endcode
   *
   * @return a reference to this, cast as SubType.
   */
  SubType &then() { return asSubType(); }

private:
  /**
   * This method exists to have just one place where the downcast is performed.
   *
   * @return this, cast to the type of SubType.
   */
  SubType &asSubType() { return *dynamic_cast<SubType *>(this); }
};

} // namespace publicdomain::testsnippets::behavioural
