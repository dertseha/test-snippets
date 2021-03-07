using System;

namespace PublicDomain.TestSnippets.Samples
{
    public class RandomSamples
    {
        private static readonly Random Rand = new(Environment.TickCount);

        public static string ARandomName() {
            return SomeFirstName() + " Doe";
        }

        public static String SomeFirstName() {
            string[] names = {"Alice", "Bob", "Carol", "David" };
            return names[ARandomIndexFor(names.Length)];
        }
        
        public static int ARandomIndexFor(int limit) => Math.Abs(ARandomNumber() % limit);
        
        public static int ARandomNumber() => Rand.Next();
    }
}