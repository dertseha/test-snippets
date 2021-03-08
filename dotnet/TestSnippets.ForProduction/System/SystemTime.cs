using System;

namespace PublicDomain.TestSnippets.System
{
    /// <summary>
    /// <see cref="SystemTime"/> provides date/time values from the system.
    /// </summary>
    public class SystemTime: ITime
    {
        /// <inheritdoc cref="ITime"/>
        public DateTime Now => DateTime.UtcNow;
    }
}