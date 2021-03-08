using System;

namespace PublicDomain.TestSnippets.System
{
    /// <summary>
    /// <see cref="SimulatedTime"/> is used instead of <see cref="SystemTime"/> to allow tests to control the passage of time.
    /// 
    /// The start value is an arbitrary value.
    /// </summary>
    public class SimulatedTime: ITime
    {
        public DateTime Now { get; set; } = new(2010, 1, 1, 12, 0, 0, DateTimeKind.Utc);

        /// <summary>
        /// Pass adds the given duration to the current value of now.
        /// </summary>
        /// <param name="span">How much time shall be added to the current value. This value can be a negative duration.</param>
        public void Pass(TimeSpan span)
        {
            Now += span;
        }
    }
}