using System;

namespace PublicDomain.TestSnippets.System
{
    /// <summary>
    /// <see cref="Time"/> provides an abstraction of the current date/time.
    /// The values provided by this interface may be affected by changes in the system,
    /// such as user intervention or time-synchronization.
    /// </summary>
    public interface Time
    {
        /// <summary>
        /// The current date/time in UTC.
        /// </summary>
        DateTime Now { get; }
    }
}