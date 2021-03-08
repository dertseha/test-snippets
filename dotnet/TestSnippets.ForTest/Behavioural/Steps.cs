namespace PublicDomain.TestSnippets.Behavioural
{
    /// <summary>
    /// <see cref="Steps{TSubType}"/> provides a standard set of starting words for test steps. These are based on the
    /// <a href="https://en.wikipedia.org/wiki/Behavior-driven_development#Behavioral_specifications">behavioural specifications</a>,
    /// used in Behaviour-driven development (BDD). Note that using this does NOT make your tests BDD-tests.
    /// There is far more to BDD than using the three steps of Given-When-Then.
    /// 
    /// The intention of this is to provide a handrail for writing tests.
    /// Tests are typically written in an Arrange-Act-Assert manner, and instead of using these clunky names, more appropriate
    /// words are used to start a human-readable sentence.
    /// 
    /// See also the article "<a href="https://dannorth.net/whats-in-a-story/">What's in a story?</a>" by Dan North.
    /// 
    /// The interface uses recursive generics pattern to allow the step methods provide access to possible extension methods
    /// in the implementing test.
    /// </summary>
    /// <example>
    /// abstract class ATestBase&lt;TSubType&gt;: Steps&lt;TSubType&gt; where TSubType: ATestBase&lt;TSubType&gt;
    /// {
    ///    // ...
    ///    public Server Server()
    ///    {
    ///       return serverFixture;
    ///    }
    ///    // ...
    /// }
    /// class ExampleTest: ATestBase&lt;ExampleTest&gt;
    /// {
    ///    [Fact]
    ///    public void example()
    ///    {
    ///        Given().Server().KnowsUser();
    ///        When().Client().LogsIn();
    ///        Then().Database().ShouldHaveActiveUserCountOf(1);
    ///    }
    /// }
    /// </example>
    /// <typeparam name="TSubType">The test type deriving from this class</typeparam>
    public abstract class Steps<TSubType> where TSubType: Steps<TSubType>
    {
        /// <summary>
        /// Given steps are those setting up the system/instance under test. They arrange for the actual act to happen.
        /// These steps may contain assertions within them, to ensure a proper setup. These assertions should not be used
        /// as actual test evidence, as corresponding assertions should exist in dedicated tests.
        ///
        /// Tests can have any number of steps, from zero to several. The ideal number is one. Given steps should be the
        /// first ones of a test, followed by a When step.
        /// 
        /// Given steps should be named using past tense or state facts. They indicate preconditions for the act.
        /// </summary>
        /// <example>
        /// Given().Configuration().EnablesLoggingLevelDebug();
        /// Given().Server().KnowsUser();
        /// Given().Client().LoggedIn();
        /// </example>
        /// <returns>this as TSubType</returns>
        public TSubType Given() => ThisAsSubType();

        /// <summary>
        /// When steps are those performing the act that triggers the test subject for the action that is being tested.
        /// 
        /// Tests should have exactly one When step that follows all Given steps. If the test fails, the action of this
        /// When step should be the one to be investigated.
        /// 
        /// When steps should be named in present verb form. They indicate the action the test observes.
        /// </summary>
        /// <example>
        /// When().Client().LogsIn();
        /// When().MessageSystem().DeliversMessage();
        /// When().Server().ClosesConnections();
        /// </example>
        /// <returns>this as TSubType</returns>
        public TSubType When() => ThisAsSubType();

        /// <summary>
        /// Then steps perform the assertions. They verify that certain conditions are reached.
        /// 
        /// Tests should have exactly one Then step. This depends on the assertion library used and the approach how
        /// assertions are treated: Should a test report all non-matched conditions, or abort at the first failed assertion.
        /// 
        /// Then steps should be named with a conditional. If a test breaks, it may be that the assumptions of the test
        /// no longer match and they may need adaption. For a more detailed reasoning, see
        /// <a href="https://dannorth.net/introducing-bdd/">Introducing BDD</a> by Dan North.
        /// </summary>
        /// <example>
        /// Then().Database().ShouldHaveActiveUserCountOf(1);
        /// Then().Client().ShouldReceiveAnErrorResponse();
        /// Then().Server().ShouldHaveAPendingLogInRequest();
        /// </example>
        /// <returns>this as TSubType</returns>
        public TSubType Then() => ThisAsSubType();

        /// <summary>
        /// And provides an alternative to avoid repeating the same introduction step method.
        /// </summary>
        /// <returns></returns>
        public TSubType And() => ThisAsSubType();
        
        /// <summary>
        /// This method exists to have just one place where the downcast is performed.
        /// </summary>
        /// <returns>this, cast to the type of TSubType</returns>
        private TSubType ThisAsSubType() => (TSubType) this;
    }
}