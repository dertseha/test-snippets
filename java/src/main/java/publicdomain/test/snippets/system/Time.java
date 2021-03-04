package publicdomain.test.snippets.system;

import java.time.Instant;

/**
 * {@link Time} provides an abstraction of the current date/time. The values provided by this interface may be affected
 * by changes in the system, such as user intervention or time-synchronization.
 */
public interface Time {
    /**
     * @return the current date/time.
     */
    Instant now();
}
