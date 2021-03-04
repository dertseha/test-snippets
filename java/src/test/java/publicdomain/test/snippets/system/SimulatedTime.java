package publicdomain.test.snippets.system;

import java.time.Duration;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneOffset;

/**
 * {@link SimulatedTime} is used instead of {@link SystemTime} to allow tests to control the passage of time.
 * <p>
 * The start value is an arbitrary value.
 */
public class SimulatedTime implements Time {

    private Instant now = LocalDateTime.of(2010, 1, 1, 12, 0, 0).toInstant(ZoneOffset.UTC);

    @Override
    public Instant now() {
        return now;
    }

    /**
     * Set changes the current time to the given value. This is for cases a test needs a specific date/time.
     *
     * @param now the new value for now
     */
    public void set(final Instant now) {
        this.now = now;
    }

    /**
     * Pass adds the given duration to the current value of now.
     *
     * @param duration how much time shall be added to the current value. This value can be a negative duration.
     */
    public void pass(final Duration duration) {
        now = now.plus(duration);
    }
}