package publicdomain.test.examples.behavioural;

import org.junit.jupiter.api.Test;

import java.time.Duration;

import static org.hamcrest.CoreMatchers.equalToObject;
import static org.hamcrest.MatcherAssert.assertThat;

public class SampleBehaviouralTest extends ATestBase<SampleBehaviouralTest> {
    /**
     * This test case is an example on how steps would be used.
     */
    @Test
    public void demonstrationOfSteps() {
        when().time().passes(Duration.ofDays(2));
        then().specialCaseShouldBeFulfilled();
    }

    /**
     * This method is an example for a test-specific step.
     */
    private void specialCaseShouldBeFulfilled() {
        assertThat(true, equalToObject(true));
    }
}
