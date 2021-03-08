using PublicDomain.TestSnippets.Fixtures;

namespace PublicDomain.TestSnippets.Behavioural
{
    /// <summary>
    /// <see cref="ATestBase{TSubType}"/> is an example how a <see cref="Steps{TSubType}"/>-based test framework with
    /// common fixtures could be set up.
    /// 
    /// Having an abstract class with all the fixtures is not always necessary, single tests could implement
    /// <see cref="Steps{SubType}"/> directly.
    /// Integration tests are primary examples of candidates that need (most of) the surrounding fixtures of a
    /// system under test.
    /// 
    /// As a recommendation, fixtures should represent collaborators on the external interfaces of the system/component.
    /// </summary>
    /// <typeparam name="TSubType">The test type deriving from this class</typeparam>
    public abstract class ATestBase<TSubType>: Steps<TSubType> where TSubType: ATestBase<TSubType>
    {
        private readonly SimulatedTimeFixture _time = new();
        
        public SimulatedTimeFixture Time() {
            return _time;
        }
    }
}
