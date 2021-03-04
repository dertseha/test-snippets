package publicdomain.test.snippets.samples;

import java.security.SecureRandom;

public class RandomSamples {
    private static final SecureRandom RAND = new SecureRandom();

    public static String aRandomName() {
        return someFirstName() + " Doe";
    }

    public static String someFirstName() {
        final String[] names = new String[]{"Alice", "Bob", "Carol", "David" };
        return names[aRandomIndexFor(names.length)];
    }

    public static int aRandomIndexFor(final int limit) {
        return (int) Math.abs(aRandomNumber() % (long) limit);
    }

    public static long aRandomNumber() {
        return RAND.nextLong();
    }
}
