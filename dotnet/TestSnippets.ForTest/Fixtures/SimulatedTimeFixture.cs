using System;
using PublicDomain.TestSnippets.System;

namespace PublicDomain.TestSnippets.Fixtures
{
    /// <summary>
    /// <see cref="SimulatedTimeFixture"/> handles an instance of <see cref="SimulatedTime"/> as a test fixture.
    /// 
    /// Depending on how the system under test receives the reference to the <see cref="Time"/>,
    /// the fixture could provide a getter to retrieve the instance, and the test could inject it.
    /// </summary>
    public class SimulatedTimeFixture
    {
        private readonly SimulatedTime time = new();

        public void Passes(TimeSpan span)
        {
            time.Pass(span);
        }
    }
}