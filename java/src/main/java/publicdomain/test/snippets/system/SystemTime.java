package publicdomain.test.snippets.system;

import java.time.Instant;

/**
 * {@link SystemTime} provides date/time values from the system.
 * <p>
 * In case {@link Time} has only one method, instead of using this class, you could also use a method reference of
 * {@link Instant#now()}.
 */
public class SystemTime implements Time {
    @Override
    public Instant now() {
        return Instant.now();
    }
}
