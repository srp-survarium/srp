const char *__cdecl vostok::logging::verbosity_to_string(vostok::logging::verbosity verbosity)
{
  const char *result; // eax

  switch ( verbosity )
  {
    case silent:
      result = "silent";
      break;
    case error:
      result = "ERROR";
      break;
    case warning:
      result = "Warning";
      break;
    case info:
      result = "info";
      break;
    case debug:
      result = "debug";
      break;
    case trace:
      result = "trace";
      break;
  }
  return result;
}
