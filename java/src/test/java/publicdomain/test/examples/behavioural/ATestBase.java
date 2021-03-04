package publicdomain.test.examples.behavioural;

import publicdomain.test.snippets.behavioural.Steps;
import publicdomain.test.snippets.fixtures.SimulatedTimeFixture;

/**
 * {@link ATestBase} is an example how a {@link Steps}-based test framework with common fixtures could be set up.
 * <p>
 * Having an abstract class with all the fixtures is not always necessary, single tests could implement {@link Steps}
 * directly. Integration tests are primary examples of candidates that need (most of) the surrounding fixtures of a
 * system under test.
 * <p>
 * As a recommendation, fixtures should represent collaborators on the external interfaces of the system/component.
 *
 * @param <SubType>
 */
public abstract class ATestBase<SubType extends ATestBase<SubType>> implements Steps<SubType> {
    private final SimulatedTimeFixture time = new SimulatedTimeFixture();

    public SimulatedTimeFixture time() {
        return time;
    }
}
