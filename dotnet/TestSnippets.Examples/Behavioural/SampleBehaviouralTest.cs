using System;
using Xunit;

namespace PublicDomain.TestSnippets.Behavioural
{
    public class SampleBehaviouralTest: ATestBase<SampleBehaviouralTest>
    {
        [Fact]
        public void DemonstrationOfSteps()
        {
            When().Time().Passes(TimeSpan.FromDays(2));
            Then().SpecialCaseShouldBeFulfilled();
        }

        /// <summary>
        /// This method is an example for a test-specific step.
        /// </summary>
        private void SpecialCaseShouldBeFulfilled() {
            Assert.True(true);
        }
    }
}