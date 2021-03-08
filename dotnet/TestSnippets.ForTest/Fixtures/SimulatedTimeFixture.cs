using System;
using PublicDomain.TestSnippets.System;

namespace PublicDomain.TestSnippets.Fixtures
{
    /// <summary>
    /// <see cref="SimulatedTimeFixture"/> handles an instance of <see cref="SimulatedTime"/> as a test fixture.
    /// 
    /// Depending on how the system under test receives the reference to the <see cref="ITime"/>,
    /// the fixture could provide a getter to retrieve the instance, and the test could inject it.
    /// </summary>
    public class SimulatedTimeFixture
    {
        private readonly SimulatedTime _time = new();

        public void Passes(TimeSpan span)
        {
            _time.Pass(span);
        }
    }
}