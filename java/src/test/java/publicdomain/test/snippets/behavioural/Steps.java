package publicdomain.test.snippets.behavioural;

/**
 * {@link Steps} provides a standard set of starting words for test steps. These are based on the
 * <a href="https://en.wikipedia.org/wiki/Behavior-driven_development#Behavioral_specifications">behavioural specifications</a>,
 * used in Behaviour-driven development (BDD). Note that using this does NOT make your tests BDD-tests.
 * There is far more to BDD than using the three steps of Given-When-Then.
 * <p>
 * The intention of this is to provide a handrail for writing tests.
 * Tests are typically written in an Arrange-Act-Assert manner, and instead of using these clunky names, more appropriate
 * words are used to start a human-readable sentence.
 * <p>
 * See also the article "<a href="https://dannorth.net/whats-in-a-story/">What's in a story?</a>" by Dan North.
 * <p>
 * The interface uses recursive generics pattern to allow the step methods provide access to possible extension methods
 * in the implementing test.
 * <p>
 * The following is an example for tests that use dedicated fixtures for collaborators.
 * <pre>
 * {@code
 * abstract class ATestBase<SubType extends ATestBase<SubType>> implements Steps<SubType> {
 *     // ...
 *     public Server server() {
 *         return serverFixture;
 *     }
 *     // ...
 * }
 *
 * class ExampleTest extends ATestBase<ExampleTest> {
 *     @Test
 *     public void example() {
 *         given().server().knowsUser();
 *         when().client().logsIn();
 *         then().database().shouldHaveActiveUserCountOf(1);
 *     }
 * }
 * }
 * </pre>
 *
 * @param <SubType> The type that this interface implements.
 */
public interface Steps<SubType extends Steps<SubType>> {
    /**
     * Given steps are those setting up the system/instance under test. They arrange for the actual act to happen.
     * These steps may contain assertions within them, to ensure a proper setup. These assertions should not be used
     * as actual test evidence, as corresponding assertions should exist in dedicated tests.
     * <p>
     * Tests can have any number of steps, from zero to several. The ideal number is one. Given steps should be the
     * first ones of a test, followed by a When step.
     * <p>
     * Given steps should be named using past tense or state facts. They indicate preconditions for the act.
     * <p>
     * Examples:
     * <pre>
     * {@code
     * given().configuration().enablesLoggingLevelDebug();
     * given().server().knowsUser();
     * given().client().loggedIn();
     * }
     * </pre>
     *
     * @return this as SubType
     */
    default SubType given() {
        return thisAsSubType();
    }

    /**
     * When steps are those performing the act that triggers the test subject for the action that is being tested.
     * <p>
     * Tests should have exactly one When step that follows all Given steps. If the test fails, the action of this
     * When step should be the one to be investigated.
     * <p>
     * When steps should be named in present verb form. They indicate the action the test observes.
     * <p>
     * Examples:
     * <pre>
     * {@code
     * when().client().logsIn();
     * when().messageSystem().deliversMessage();
     * when().server().closesConnections();
     * }
     * </pre>
     *
     * @return this as SubType
     */
    default SubType when() {
        return thisAsSubType();
    }

    /**
     * Then steps perform the assertions. They verify that certain conditions are reached.
     * <p>
     * Tests should have exactly one Then step. This depends on the assertion library used and the approach how
     * assertions are treated: Should a test report all non-matched conditions, or abort at the first failed assertion.
     * <p>
     * Then steps should be named with a conditional. If a test breaks, it may be that the assumptions of the test
     * no longer match and they may need adaption. For a more detailed reasoning, see
     * <a href="https://dannorth.net/introducing-bdd/">Introducing BDD</a> by Dan North.
     * <p>
     * Examples:
     * <pre>
     * {@code
     * then().database().shouldHaveActiveUserCountOf(1);
     * then().client().shouldReceiveAnErrorResponse();
     * when().server().shouldHaveAPendingLogInRequest();
     * }
     * </pre>
     *
     * @return this as SubType
     */
    default SubType then() {
        return thisAsSubType();
    }

    /**
     * And provides an alternative to avoid repeating the same introduction step method.
     *
     * @return this as SubType
     */
    default SubType and() {
        return thisAsSubType();
    }

    /**
     * This method exists to have just one place where the downcast is performed.
     *
     * @return this, cast to the type of SubType.
     */
    @SuppressWarnings("unchecked")
    default SubType thisAsSubType() {
        return (SubType) this;
    }
}
