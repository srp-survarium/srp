vostok::logging::verbosity __cdecl vostok::logging::string_to_verbosity(const char *in_verbosity)
{
  unsigned int i; // [esp+4h] [ebp-1Ch]
  vostok::logging::verbosity verbosities[6]; // [esp+8h] [ebp-18h]

  verbosities[0] = silent;
  verbosities[1] = error;
  verbosities[2] = warning;
  verbosities[3] = info;
  verbosities[4] = debug;
  verbosities[5] = trace;
  for ( i = 0; i < 6; ++i )
  {
    if ( !vostok::strings::compare_insensitive(vostok::logging::verbosity_to_str[verbosities[i]], in_verbosity) )
      return verbosities[i];
  }
  return 0;
}
