using PublicDomain.TestSnippets.Fixtures;

namespace PublicDomain.TestSnippets.Behavioural
{
    /// <summary>
    /// <see cref="ATestBase{SubType}"/> is an example how a <see cref="Steps{SubType}"/>-based test framework with common fixtures could be set up.
    /// 
    /// Having an abstract class with all the fixtures is not always necessary, single tests could implement <see cref="Steps{SubType}"/>
    /// directly. Integration tests are primary examples of candidates that need (most of) the surrounding fixtures of a
    /// system under test.
    /// 
    /// As a recommendation, fixtures should represent collaborators on the external interfaces of the system/component.
    /// </summary>
    /// <typeparam name="SubType">The test type deriving from this class</typeparam>
    public abstract class ATestBase<SubType>: Steps<SubType> where SubType: ATestBase<SubType>
    {
        private readonly SimulatedTimeFixture time = new SimulatedTimeFixture();
        
        public SimulatedTimeFixture Time() {
            return time;
        }
    }
}
