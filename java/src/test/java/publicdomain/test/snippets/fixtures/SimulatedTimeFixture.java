package publicdomain.test.snippets.fixtures;

import publicdomain.test.snippets.system.SimulatedTime;

import java.time.Duration;

/**
 * {@link SimulatedTimeFixture} handles an instance of {@link SimulatedTime} as a test fixture.
 * <p>
 * Depending on how the system under test receives the reference to the {@link publicdomain.test.snippets.system.Time},
 * the fixture could provide a getter to retrieve the instance, and the test could inject it.
 */
public class SimulatedTimeFixture {
    private final SimulatedTime time = new SimulatedTime();

    public void passes(final Duration duration) {
        time.pass(duration);
    }
}
